#ifndef IMEDIA_HPP
#define IMEDIA_HPP

class imedia
{
private:
    /* data */
public:
    imedia();
    virtual void info() const = 0;
    virtual void play() const = 0;
    virtual ~imedia() = default;
};

#endif
