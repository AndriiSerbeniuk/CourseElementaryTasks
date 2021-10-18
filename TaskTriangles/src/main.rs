mod triangles_lib;

fn main() 
{
    unsafe
    {
        let mut dialog = triangles_lib::TrianglesApi::new();
        
        while dialog.AskStart()
        {
            dialog.AskTriangle();
            let table = cstr_to_string(dialog.FormTrianglesTable());
            println!("{}", table);
        }

        dialog.destruct();
    }
}

fn cstr_to_string(raw_cstr: *mut i8) -> String
{
    unsafe
    {
        let board_c = std::ffi::CStr::from_ptr(raw_cstr);
        let board = board_c.to_str().unwrap_or("Error");
        board.to_string()
    }
}

#[cfg(test)]
mod tests
{
    fn get_triangle(args: &std::ffi::CString) -> *mut std::ffi::c_void
    {
        let triangle;

        unsafe
        {
            let mut dialog = super::triangles_lib::TrianglesApi::new();
            triangle = dialog.GetTriangle(args.as_ptr());
            dialog.destruct();
        }

        triangle
    }

    #[test]
    fn valid_triangle()
    {
        let tr_args = std::ffi::CString::new("\ttriangle 1  ,3  , 4,5").unwrap();
        let tr_obj = get_triangle(&tr_args);
        assert!(!tr_obj.is_null());        
    }

    #[test]
    #[should_panic]
    fn invalid_triangle()
    {
        let tr_args = std::ffi::CString::new("triangle 1, 6 cm").unwrap();
        let tr_obj = get_triangle(&tr_args);
        assert!(!tr_obj.is_null());
    }

    #[test]
    fn valid_sorting()
    {
        let mut dialog = unsafe { super::triangles_lib::TrianglesApi::new() };
        let tr_args = vec![
            std::ffi::CString::new("t1, 6, 4, 9").unwrap(),
            std::ffi::CString::new("t2, 3, 4, 5").unwrap(),
            std::ffi::CString::new("t3, 10, 12, 15").unwrap()
        ];

        for args in tr_args
        {
            let tr_obj = get_triangle(&args);
            unsafe { dialog.AddTriangle(tr_obj); }
        }

        let table = super::cstr_to_string(unsafe { dialog.FormTrianglesTable() });
        let expected = "\n============== Triangles list ==============\n\
                        1. [t3]: 59.811684 cm\n\
                        2. [t1]: 9.562296 cm\n\
                        3. [t2]: 6.000000 cm\n";
        
        assert_eq!(table, expected);
    }
}
