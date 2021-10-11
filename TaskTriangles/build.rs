extern crate bindgen;

fn main()
{
    println!("cargo:rerun-if-changed=includes.hpp");

    // Library compilation
    let mut source_files = vec![ 
        "AccessFunction".to_string(), 
        "ITriangle".to_string(),
        "StringExtractor".to_string(),
        "Triangle".to_string(),
        "TriangleFactory".to_string(), 
        "UserDialog".to_string()];
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
        .header("includes.hpp")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings")
        .write_to_file("src/triangles_lib.rs")
        .expect("Unable to write the bindings into a file");
}
