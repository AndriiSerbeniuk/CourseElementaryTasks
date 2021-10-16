#pragma once
#include "Ticket.hpp"

class TicketsRangeGenerator
{
public:
    struct GenIterator  // TODO: make end range value inclusive
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = const Ticket;
        using pointer = const Ticket*;
        using reference = const Ticket&;

        GenIterator(const Ticket& begin, const Ticket& end);

        reference operator*() const;
        pointer operator->() const;

        GenIterator& operator++();
        GenIterator operator++(int);

        friend bool operator==(const GenIterator& lhs, const GenIterator& rhs);
        friend bool operator!=(const GenIterator& lhs, const GenIterator& rhs);

    private:
        static const char s_top_digit;
        static const char s_bottom_digit;

        Ticket m_begin;
        Ticket m_end;

        Ticket next();
    };

    TicketsRangeGenerator(const Ticket& begin, const Ticket& end);

    GenIterator begin();
    GenIterator end();

private:
    Ticket m_begin;
    Ticket m_end;
};
