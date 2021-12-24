#ifndef GUARD_Picture_h
#define GUARD_Picture_h

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "Ptr.h"

// Forward declarations
class Picture;
class VCat_Pic;
class HCat_Pic;
class Frame_Pic;
class String_Pic;

class Pic_base {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend VCat_Pic;
    friend HCat_Pic;
    friend Frame_Pic;
    friend String_Pic;

    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type wd_sz;

    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream&, ht_sz, bool) const = 0;

    public:
        virtual ~Pic_base() {}

    protected:
        static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
            while (beg != end) {
                os << " ";
                ++beg;
            }
        }
};

class Picture {
    friend Picture frame(const Picture&, const char, const char, const char); 
    friend Picture hcat(const Picture&, const Picture&);
    friend Picture vcat(const Picture&, const Picture&);
    friend std::ostream& operator<<(std::ostream&, const Picture&);

    public:
        Picture(const std::vector<std::string>& = std::vector<std::string>());
        Picture(Pic_base* ptr) : m_base(ptr) {}

    private:
        Ptr<Pic_base> m_base;
};

class String_Pic : public Pic_base {
    static const bool DEBUG = false;
    friend class Picture;

    std::vector<std::string> data;
    String_Pic(const std::vector<std::string>& v) : data(v) 
        { if (DEBUG) std::cout << "String_Pic::String_Pic(const std::vector<std::string>&)" << '\n';}

    wd_sz width() const {
        wd_sz n = 0;
        for (ht_sz i = 0; i != data.size(); ++i)
            n = std::max(n, data[i].size());
        return n;
    };
    ht_sz height() const { return data.size(); }
    void display(std::ostream& os, ht_sz row, bool do_pad) const {
        wd_sz start = 0;
        if (row < height()) {
            os << data[row];
            start = data[row].size();
        }
        // pad the output if necessary
        if (do_pad) {
            pad(os, start, width());
        }
    };
};
class Frame_Pic : public Pic_base {
    friend Picture frame(const Picture&, const char, const char, const char); 
    Frame_Pic(const Ptr<Pic_base>& pic, const char side, const char corner, const char top_bottom) 
        : p(pic), side(side), corner(corner), top_bottom(top_bottom) {}

    wd_sz width() const { return p->width() + 4; }
    ht_sz height() const { return p->height() + 4; }
    void display(std::ostream& os, ht_sz row, bool do_pad) const {
       if (row >= height()) {
           // out of range
           if (do_pad) {
               pad(os, 0, width());
           }
       } else {
           if (row == 0 || row == height() - 1) {
               // top or bottom row
               os << std::string(1, corner) + std::string(width() - 2, top_bottom) + std::string(1, corner);
           } else if (row == 1 || row == height() - 2) {
               // second from top or bottom row
               os << side;
               pad(os, 1, width() - 1);
               os << side;
           } else {
               // interior row
               os << side << " ";
               p->display(os, row - 2, true);
               os << " " << side;
           }
       }
    };

    Ptr<Pic_base> p;
    char side;
    char corner;
    char top_bottom;
};
class VCat_Pic : public Pic_base {
    friend Picture vcat(const Picture&, const Picture&);

    Ptr<Pic_base> top, bottom;
    VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b) : top(t), bottom(b) {}

    wd_sz width() const { return std::max(top->width(), bottom->width()); }
    ht_sz height() const { return top->height() + bottom->height(); }
    void display(std::ostream& os, ht_sz row, bool do_pad) const
    {
        wd_sz w = 0;
        if (row < top->height()) {
            top->display(os, row, do_pad);
            w = top->width();
        } else if (row < height()) {
            bottom->display(os, row - top->height(), do_pad);
            w = bottom->width();
        }
        
        if(do_pad) 
            pad(os, w, width());
    };
};
class HCat_Pic : public Pic_base {
    friend Picture hcat(const Picture&, const Picture&);
    
    Ptr<Pic_base> l, r;
    HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r) : l(l), r(r) {}

    wd_sz width() const { return l->width() + r->width(); }
    ht_sz height() const { return std::max(l->height(), r->height()); }
    void display(std::ostream& os, ht_sz row, bool do_pad) const {
        l->display(os, row, do_pad || row < r->height());
        r->display(os, row, do_pad);
    };
};

// Picture constructor from a vector<string>
inline Picture::Picture(const std::vector<std::string>& v) : m_base(new String_Pic(v)) {}

inline Picture frame(const Picture& pic, const char side = '*', const char corner = '*', const char top_bottom = '*') { 
    return new Frame_Pic(pic.m_base, side, corner, top_bottom); 
}
inline Picture reframe(Picture& pic, 
                       const char side = '*', const char corner = '*', const char top_bottom = '*') {
    return pic;
};
inline Picture hcat(const Picture& l, const Picture& r) { return new HCat_Pic(l.m_base, r.m_base); }
inline Picture vcat(const Picture& t, const Picture& b) { return new VCat_Pic(t.m_base, b.m_base); }

inline std::ostream& operator<<(std::ostream& os, const Picture& picture)
{
    const Pic_base::ht_sz ht = picture.m_base->height();
    for (Pic_base::ht_sz i = 0; i != ht; ++i) {
        picture.m_base->display(os, i, false);
        os << '\n';
    }
    return os;
}

#endif
