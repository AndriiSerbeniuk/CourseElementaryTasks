extern crate bindgen;

fn main()
{
    println!("cargo:rerun-if-changed=includes.hpp");

    // Library compilation
    let mut source_files = vec![
        //"main".to_string(), 
        "chess_board".to_string(), 
        "chess_board_drawer".to_string(), 
        "string_drawer".to_string()];
    let files_folder = "TaskChessboardCpp/src/".to_string();
    let files_extension = ".cpp".to_string();
    for filename in source_files.iter_mut()
    {
        filename.insert_str(0, &files_folder);
        filename.push_str(&files_extension);
    }
    //source_files.push("TaskChessboardCpp/src/main.cpp".to_owned());

    cc::Build::new()
        .cpp(true)
        .files(&source_files)
        .compile("ChessBoard");

    // Library binding
    let bindings = bindgen::Builder::default()
        .header("includes.hpp")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings")
        .write_to_file("src/ChessBoardLib.rs")
        .expect("Unable to write the bindings into a file");
}