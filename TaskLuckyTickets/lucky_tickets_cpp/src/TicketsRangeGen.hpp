#pragma once
#include "Ticket.hpp"

// Tickets generator that generates new elements on iterator increments.
// Can be interpreted as a container of a range of tickets.
class TicketsRangeGen
{
public:
    // Iterator that generates new Tickets
    struct GenIterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = const Ticket;
        using pointer = const Ticket*;
        using reference = const Ticket&;

        // Iterator end value
        static const Ticket s_end;

        GenIterator(const Ticket& begin, const Ticket& end);

        reference operator*() const;
        pointer operator->() const;

        GenIterator& operator++();
        GenIterator operator++(int);

        friend bool operator==(const GenIterator& lhs, const GenIterator& rhs);
        friend bool operator!=(const GenIterator& lhs, const GenIterator& rhs);

    private:
        // Top digit value for generating new Tickets
        static const char s_top_digit;
        // Bottom digit value for generating new Tickets
        static const char s_bottom_digit;

        // First range value
        Ticket m_begin;
        // Last range value (inclusive)
        Ticket m_end;

        // Generates next Ticket
        Ticket next();
    };

    TicketsRangeGen(const Ticket& begin, const Ticket& end);

    GenIterator begin();
    GenIterator end();

private:
    // End iterator value
    static const GenIterator s_end;

    // First range value
    Ticket m_begin;
    // Last range value (inclusive)
    Ticket m_end;
};
