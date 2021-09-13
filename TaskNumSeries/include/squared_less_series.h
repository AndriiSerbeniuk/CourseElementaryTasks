#pragma once
#include "mut_num_series.h"

class SquaredLessSeries : public MutNumSeries {
	public:
    SquaredLessSeries();
    SquaredLessSeries(int limit);
    virtual ~SquaredLessSeries();

    void set_limit(int limit);
    // Shouldn't be used in this class
    void set_limits(float bottom_limit, float top_limit);
    void set_top_limit(float limit);
    void set_bottom_limit(float limit);

	private:
    class SquaredValidator : public MutNumSeries::SeriesNumValidator {
      public:
        SquaredValidator(std::deque<float>& series, const float& bottom, const float& top);
        virtual ~SquaredValidator();
        // Default implementation already suits the task
        //float get_next_top() const;
        float get_next_bottom() const;
        void init_series();
        bool can_set_top(float number) const;
        bool can_set_bottom(float number) const;
    };
};
