#include "TicketsRangeGenerator.hpp"

TicketsRangeGenerator::TicketsRangeGenerator(const Ticket& begin, 
    const Ticket& end)
    : m_begin(begin), m_end(end)
{}

TicketsRangeGenerator::GenIterator TicketsRangeGenerator::begin()
{
    return GenIterator(m_begin, m_end);
}

TicketsRangeGenerator::GenIterator TicketsRangeGenerator::end()
{
    return GenIterator(m_end, m_end);
}
