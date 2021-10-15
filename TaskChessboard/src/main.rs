mod chess_board_lib;

fn main() 
{
    let mut args = std::env::args();

    if args.len() != 3
    {
        println!("Wrong number of arguments provided.");
        println!("Required arguments are: width height. Both arguments should be int > 0");
        return;
    }

    args.next();    // Skip executable path
    let mut wrong_arg = false;
    let width_str = args.next().unwrap();
    let height_str = args.next().unwrap();

    let width = width_str.parse::<i32>().unwrap_or_else(|_| {
        println!("{} is not a valid width.", width_str);
        wrong_arg = true;
        0
    });
    let height = height_str.parse::<i32>().unwrap_or_else(|_| {
        println!("{} is not a valid height.", height_str);
        wrong_arg = true;
        0
    });

    if wrong_arg
    {
        println!("Sides of a chessboard must be int > 0");
        return;
    }

    unsafe
    {
        let mut cb_api = chess_board_lib::AccessApi::new();
        let board_raw = cb_api.get_chessboard(width, height);   // May return error info as well
        let board_c = std::ffi::CStr::from_ptr(board_raw);
        let board = board_c.to_str().unwrap_or("Error");
        println!("{}", board);
    }
}

#[cfg(test)]
mod tests
{
    // Helper function.
    // Returns String with the result of board drawing
    fn get_board(w: i32, h: i32) -> String
    {
        unsafe
        {
            let mut cb_api = super::chess_board_lib::AccessApi::new();
            let board_raw = cb_api.get_chessboard(w, h);   // May return error info as well
            let board_c = std::ffi::CStr::from_ptr(board_raw);
            let board = board_c.to_str().unwrap_or("Error");
            board.to_string()
        }
    }

    #[test]
    fn three_by_three_board()
    {
        let board = get_board(3, 3);
        let expected = "#_#\n\
                        _#_\n\
                        #_#\n".to_string();
        assert_eq!(board, expected);
    }

    // Even width values are treated slightly differently internally
    #[test]
    fn four_by_five_board()
    {
        let board = get_board(4, 5);
        let expected = "#_#_\n\
                        _#_#\n\
                        #_#_\n\
                        _#_#\n\
                        #_#_\n".to_string();
        assert_eq!(board, expected);
    }

    // Covers cases when board side length is < 1
    #[test]
    fn zero_length()
    {
        let board = get_board(0, 1);
        let expected = "Size of 0x1 is invalid. Each dimention must be > 0.".to_owned();
        assert_eq!(board, expected);
    }
}
