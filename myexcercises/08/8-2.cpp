#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

template<class T, class In> bool g_equal(In beg, In end, T value) 
{   
    while (beg != end)
    {
        if (*beg++ == value)
        {
            return true;
        }
    }
    return false;
}

template<class In, class T> In g_find(In beg, In end, T value)
{
    while (beg != end)
    {
        if (*beg == value)
        {
            return beg;
        }
        ++beg;
    }
    return end;
}

template<class In, class Out> void g_copy(In beg, In end, Out o)
{
    while (beg != end)
    {
        *o++ = *beg++;
    }
}

template<class In, class Pred> In g_find_if(In beg, In end, Pred p)
{
    while (beg != end)
    {
        if (p(*beg)) {
            return beg;
        }
        ++beg;
    }
    return end;
}

template<class In> In g_search(In beg, In end, In s_beg, In s_end)
{
    while (beg != end)
    {
        if (*beg == *s_beg)
        {
            In pos = beg;
            In s_pos = s_beg;
            while (*s_pos == *pos)
            {
                ++s_pos; ++pos;
                if (s_pos == s_end)
                {
                    return beg;
                }
            }
        }
        ++beg;
    }
    return end;
}

template<class In, class Out, class Pred> void g_remove_copy_if(In beg, In end, Out o, Pred p)
{
    while (beg != end)
    {
        if (!p(*beg))
        {
            *o++ = *beg;
        }
        ++beg;
    }
}

template<class In, class Out, class T> void g_remove_copy(In beg, In end, Out o, const T& value)
{
    while (beg != end)
    {
        if (*beg != value)
        {
            *o++ = *beg;
        }
        ++beg;
    }
}

template<class In, class T> In g_remove(In beg, In end, const T& value)
{
   In result = beg;
   while (beg != end)
   {
       if (*beg != value) 
       {
           if (result != beg)
           {
               *result = *beg;
           }
           ++result;
       }
       ++beg;
   }
   return result;
}

template<class In, class Out, class Trans> void g_transform(In beg, In end, Out o, Trans trans) 
{
    while (beg != end)
    {
        *o++ = trans(*beg++);
    }
}

template<class In, class T> T g_accumulate(In beg, In end, T init)
{
    while (beg != end)
    {
        init += *beg++;
    }
    return init;
} 

template<class In, class Pred> In g_partition(In beg, In end, Pred pred)
{
    beg = find_if_not(beg, end, pred);
    if (beg == end) return beg;

    for (In i = next(beg); i != end; ++i)
    {
        if (pred(*i))
        {
            iter_swap(i, beg);
            ++beg;
        }
    }
    return beg;
}

bool test(int x)
{
    return x == 0;
}

int main() 
{
    vector<int> v = {1, 2, 10, 0, 0};
    return 0;
}
