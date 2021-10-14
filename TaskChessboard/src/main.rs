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
