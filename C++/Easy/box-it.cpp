

class Box
{ 
private:
    int l;
    int b;
    int h;

public: 
    Box() : l{0}, b{0}, h{0} {}
    Box(int length, int breadth, int height)
        : l{length}, b{breadth}, h{height} {}
    Box(const Box &rhs) : l{rhs.l}, b{rhs.b}, h{rhs.h} {}

    int getLength() const { return l; }
    int getBreadth () const { return b; }
    int getHeight () const { return h; }
    long long CalculateVolume() const { return static_cast<long long>(l) * b * h; }

    bool operator<(const Box& rhs);
    friend ostream& operator<<(ostream& out, Box& box);
};

bool Box::operator<(const Box& rhs)
{
    if (l > rhs.l) 
    {
        return false;
    }
    else if (l < rhs.l) 
    {
        return true;
    }

    if (b > rhs.b) {
      return false;
    }
    else if (b < rhs.b) {
      return true;
    }

    if (h >= rhs.h)
      return false;
    else return true;
}

ostream & operator<<(ostream &out, Box &B)
{
    out << B.l << " " << B.b << " " << B.h << " ";
    return out;
}
