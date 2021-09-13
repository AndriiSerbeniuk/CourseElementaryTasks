#pragma once
#include <deque>
#include <memory>

class MutNumSeries {
	public:
    virtual ~MutNumSeries();

    const std::deque<float>& get_series() const;
    virtual void set_limits(float bottom_limit, float top_limit);
    virtual void set_top_limit(float limit);
    virtual void set_bottom_limit(float limit);

	protected:
    MutNumSeries();
    MutNumSeries(float bottom_lim, float top_lim);
    class SeriesNumValidator {
      public:
        SeriesNumValidator(std::deque<float>& series, const float& botton,
         const float& top);
        virtual ~SeriesNumValidator();

        virtual float get_next_top() const;
        virtual float get_next_bottom() const;
        virtual void init_series();
        virtual bool can_set_top(float number) const;
        virtual bool can_set_bottom(float number) const;

      protected:
        const float& top_lim_;
        const float& bottom_lim_;
        std::deque<float>& series_;
    };

    std::deque<float> series_;
    float top_lim_;
    float bottom_lim_;

    void set_validator(SeriesNumValidator* validator);

	private:
    std::unique_ptr<SeriesNumValidator> validator_;

    void adjust_series();
    bool add_top();
    bool add_bottom();
    void trim_top();
    void trim_bottom();
};