extern crate bindgen;

fn main()
{
    println!("cargo:rerun-if-changed=Includes.hpp");
    println!("cargo:rerun-if-changed=TaskChessboardCpp/AccessApi.cpp");

    // Library compilation
    let mut source_files = vec![ 
        "ChessBoard".to_string(), 
        "ChessBoardDrawer".to_string(), 
        "StringDrawer".to_string()];
    let files_folder = "TaskChessboardCpp/src/".to_string();
    let files_extension = ".cpp".to_string();
    for filename in source_files.iter_mut()
    {
        filename.insert_str(0, &files_folder);
        filename.push_str(&files_extension);
    }
    source_files.push("TaskChessboardCpp/AccessApi.cpp".to_owned());

    cc::Build::new()
        .cpp(true)
        .files(&source_files)
        .compile("ChessBoard");

    // Library binding
    bindgen::Builder::default()
        .raw_line("#![allow(warnings)]")
        .header("Includes.hpp")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings")
        .write_to_file("src/chess_board_lib.rs")
        .expect("Unable to write the bindings into a file");
}