#![allow(non_snake_case)]
mod lucky_tickets_lib;

fn main() {
    
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