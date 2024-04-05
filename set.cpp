#include "set.h"

Set::Set() {
    count = 0;
    elements = nullptr;
}

Set::Set(int n, int *e) {
    int i;

    if (n) {
        for (i = 0, count = n, elements = new int[n]; i < n; i++)
        {
            elements[i] = e[i];
        }
    }
    else
    {
        count = 0;
        elements = nullptr;
    }
}

Set::~Set() {
    if (count) {
        delete elements;
    }
}

Set& Set::operator=(const Set &s) {
    int i;
    if (count) delete elements;

    count = s.count;
    if (!s.count)
    {
        elements = nullptr;
    }
    else
    {
        elements = new int[count];
        for (i = 0; i < count; i++)
            elements[i] = s.elements[i];
    }

    setSorter();
    return *this;
}

Set& Set::operator=(int i) {
    if (count) delete elements;

    count = 1;
    elements = new int[count];
    elements[0] = i;
    return *this;
}

std::ostream& operator <<(std::ostream& os, Set &s) {
    if (!s.count) {
        os << "Empty!";
        return os;
    }

    for (int i = 0; i < s.count; os << s.elements[i++] << ' ');

    return os;
}

int Set::operator==(const Set &s) {
    int i;

    if (count != s.count) return 0; // different length
    if (!count) return 1; // two empty set

    // two real set with same multiplicity
    for (i = 0; i < count; i++)
    {
        if (elements[i] != s.elements[i]) return 0;
    }

    return 1;
}

int Set::operator!=(const Set &s) {
    return !(*this == s);
}

int operator>=(const Set &a, const Set &b) {
    return b <= a;
}

int operator<=(const Set &a, const Set &b) {
    int i, ret;

    // empty set is a part set of everything
    if (!a.count) return 1;

    // a longer set cannot be part of a smaller
    if (a.count > b.count) return 0;

    // ret will be 1 if it is real part of b
    for (i = 0, ret = 1; i < a.count; i++)
    {
        ret &= (a.elements[i] < b);
    }

    return ret;
}

int operator<(const int e, const Set &b) {
    int i;
    for (i = 0; i < b.count; i++)
    {
        if (e == b.elements[i]) return 1;
    }
    return 0;
}

Set& operator +(const Set &a, const Set &b) {
    int i, j, m;
    int n = a.count + b.count;
    int l = n;
    int *cElements;
    Set &ret = *(new Set(1, nullptr));

    if (n) {
        cElements = new int[n];

        for (i = 0; i < a.count; i++)
        {
            cElements[i] = a.elements[i];
        }

        for (j = 0, m = 0; j < b.count; j++)
        {
            // < (operator of contains in Sets)
            if (!(b.elements[j] < a)) cElements[i + m++] = b.elements[j];
        }

        n = a.count + m;
        Set c(n, cElements);
        delete cElements;
        ret = c;
    }
    return ret;
}

static int cmp(const void *a, const void *b) {
    return -1 * ((*((int*)a))) < (*((int*) b)) +
            1 * ((*((int*)a))) > (*((int*) b));
}

Set& operator+(const int e, const Set &a)
{
    return a + e; // return it to set plus int
}

Set& Set::operator+=(const Set &s) {
    int i;
    Set a(count, elements);
    a = a + s;
    delete elements;

    count = a.count;
    elements = new int[count];
    for (i = 0; i < count; i++)
    {
        elements[i] = a.elements[i];
    }

    return *this;
}

Set& operator*(const Set &a, const Set &b) {
    int i, m, n, l;
    int *cElements; // for section / incision
    Set bigger(0, nullptr), smaller(0, nullptr);

    if (a.count > b.count) {
        n = a.count;
        m = b.count;
        bigger = a;
        smaller = m;
    }
    else
    {
        n = b.count;
        m = a.count;
        bigger = b;
        smaller = a;
    }

    // The section cannot be bigger than the maximum set's size.

    cElements = new int[n];

    l = n;
    n = 0;

    // now, we store 'how many numbers are same in both set
    // we check the smaller set values that they are in the bigger set
    // if it is then It will move to the section

    for (i = 0; i < m; i++)
    {
        if (smaller.elements[i] < bigger)
        {
            cElements[n++] = smaller.elements[i];
        }
    }

    Set c(n, cElements);
    delete cElements;
    Set ret = c;
    return ret;
}

void Set::setSorter() {
    qsort(elements, count, sizeof (int), cmp);
}

Set &operator+(const Set &a, const int element) {
    int *el = new int;
    *el = element;
    Set b(1, el);
    delete el;
    return a+b;
}
