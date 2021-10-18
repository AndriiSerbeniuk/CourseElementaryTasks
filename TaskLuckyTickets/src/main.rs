#![allow(non_snake_case)]
mod lucky_tickets_lib;

use std::ffi::CString;
use lucky_tickets_lib::*;

fn main() 
{
    // Getting file path
    let mut filepath = String::new();
    println!("Enter the path to the algorithm file:");

    match std::io::stdin().read_line(&mut filepath)
    {
        Ok(_) => filepath = filepath.trim().to_string(),
        Err(error) => 
        {
            println!("{}", error);
            return;
        }
    }
    // Reading the file
    let file_contents = std::fs::read_to_string(filepath).expect("Error while reading the file");
    let city_name = CString::new(file_contents).expect("Error while interpreting file contents");
    // Processing file contents
    unsafe
    {
        if IsCityValid(city_name.as_ptr())
        {
            println!("City name of {:?} is valid.", city_name); 
        }
        else
        {
            println!("City name is not valid. Valid names are: Moscow, Piter");
        }
    }
    // Counting lucky tickets
    let range_start = CString::new("000000").unwrap();
    let range_end = CString::new("999999").unwrap();

    unsafe
    {
        let lucky_count = CountLucky(range_start.as_ptr(), range_end.as_ptr(),
            city_name.as_ptr());
        
        if -1 == lucky_count
        {
            println!("Error while counting lucky tickets.");
        }
        else
        {
            println!("Number of lucky {:?} tickets in the {:?}-{:?} range is: {}.",
                city_name, range_start, range_end, lucky_count);
        }
    }
}

#[cfg(test)]
mod tests
{
    use std::ffi;

    #[test]
    fn moscow_lucky()
    {
        let ticket_num = ffi::CString::new("123321").unwrap();
        let city_name = ffi::CString::new("moscow").unwrap();
        let lucky;
        unsafe 
        { 
            lucky = super::lucky_tickets_lib::IsLucky(ticket_num.as_ptr(), city_name.as_ptr());
        }

        assert!(lucky);
    }

    #[test]
    #[should_panic]
    fn moscow_unlucky()
    {
        let ticket_num = ffi::CString::new("123456").unwrap();
        let city_name = ffi::CString::new("moscow").unwrap();
        let lucky;
        unsafe 
        { 
            lucky = super::lucky_tickets_lib::IsLucky(ticket_num.as_ptr(), city_name.as_ptr());
        }

        assert!(lucky);
    }

    #[test]
    fn piter_lucky()
    {
        let ticket_num = ffi::CString::new("143341").unwrap();
        let city_name = ffi::CString::new("piter").unwrap();
        let lucky;
        unsafe 
        { 
            lucky = super::lucky_tickets_lib::IsLucky(ticket_num.as_ptr(), city_name.as_ptr());
        }

        assert!(lucky);
    }

    #[test]
    #[should_panic]
    fn piter_unlucky()
    {
        let ticket_num = ffi::CString::new("123456").unwrap();
        let city_name = ffi::CString::new("piter").unwrap();
        let lucky;
        unsafe 
        { 
            lucky = super::lucky_tickets_lib::IsLucky(ticket_num.as_ptr(), city_name.as_ptr());
        }

        assert!(lucky);
    }

    #[test]
    fn range_count()
    {
        let start_ticket = ffi::CString::new("555555").unwrap();
        let end_ticket = ffi::CString::new("999999").unwrap();
        let city_name = ffi::CString::new("piter").unwrap();

        let lucky_count;
        unsafe 
        { 
            lucky_count = super::lucky_tickets_lib::CountLucky(
            start_ticket.as_ptr(), end_ticket.as_ptr(), city_name.as_ptr());
        }

        assert_eq!(lucky_count, 9171);
    }
}