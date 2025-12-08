#include <vector>

template<typename T>
class Iterator
{
public:
    virtual void first () = 0;
    virtual void next () = 0;
    virtual bool isEnd () = 0;
    virtual T& current () = 0;
    virtual ~Iterator () = default;
};

template <typename T>
class ConcreteIterator;

template<typename T>
class MyCollection
{
public:
    Iterator<T>* GetIterator ()
    {
        // ...
        return new ConcreteIterator<T> (*this);
    }

    void Add (const T& element)
    {
        vec.push_back (element);
    }

    void Delete ()
    {
        vec.erase ();
    }

    std::vector<T>& GetData ()
    {
        return vec;
    }

private:
    std::vector<T> vec;
};

template<typename T>
class ConcreteIterator :public Iterator<T>
{
public:
    ConcreteIterator (const MyCollection<T>& mc)
        :m_mc (mc)
    {

    }

    virtual void first () override
    {
        index = 0;
    }
    virtual void next () override
    {
        ++index;
    }
    virtual bool isEnd () override
    {
        return index >= m_mc.GetData ().size ();
    }
    virtual T& current () override
    {
        return m_mc.GetData ().at (index);
    }

private:
    MyCollection<T> m_mc;
    mutable std::size_t index;
};

