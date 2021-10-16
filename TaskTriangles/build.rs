extern crate bindgen;

fn main()
{
    println!("cargo:rerun-if-changed=Includes.hpp");

    // Library compilation
    let mut source_files = vec![ 
        "ITriangle".to_string(),
        "AreaTriangle".to_string(),
        "StringArgsExtractor".to_string(),
        "AreaTriangleFactory".to_string(), 
        "UserDialog".to_string(),
        "TrianglesApi".to_string()]; 
    let files_folder = "TaskTrianglesCpp/src/".to_string();
    let files_extension = ".cpp".to_string();
    
    for filename in source_files.iter_mut()
    {
        filename.insert_str(0, &files_folder);
        filename.push_str(&files_extension);
    }

    cc::Build::new()
        .cpp(true)
        .files(&source_files)
        .compile("triangles");

    // Library binding
    bindgen::Builder::default()
        .raw_line("#![allow(warnings)]")
        .header("Includes.hpp")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings")
        .write_to_file("src/triangles_lib.rs")
        .expect("Unable to write the bindings into a file");
}
