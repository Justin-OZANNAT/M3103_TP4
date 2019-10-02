#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP
#include <memory.h> // shared_ptr (), ...
#include <iostream> // rand ()
#include "node.hpp"

template <typename T>
class BSTree
{
  private:
    std::shared_ptr<CNode<T>> m_Root;
    //void localAdd (const std::shared_ptr<CNode<T>> & ptr, const T &Val);
   // void localShow (const std::shared_ptr<CNode<T>> & ptr);
  public:
    BSTree (const T & val);
    ~ BSTree() {}
    void add (const T & Val);
    void show () const;
};

template<typename T>
BSTree<T>::BSTree(const T &val)
{
    std::shared_ptr<CNode <T>> tmp (new CNode<T> (val));
    m_Root = tmp;
}

template<typename T>
void localAdd (const std::shared_ptr<CNode<T>> & ptr, const T &Val)
{
    if (ptr->GetData () > Val)
    {
        if (ptr->getLC() == nullptr)
        {
            std::shared_ptr<CNode <T>> tmp (new CNode<T> (Val));
            ptr->setLC(tmp);
            return;
        }
        else localAdd (ptr->getLC(), Val);
    }
    else
    {
        if (ptr->getRC () == nullptr)
        {
            std::shared_ptr<CNode <T>> tmp (new CNode<T> (Val));
            ptr->setRC(tmp);
            return;
        }
        else localAdd (ptr->getRC(), Val);
    }
}

template<typename T>
void BSTree<T>::add(const T &Val)
{
    localAdd (m_Root, Val);
}


template<typename T>
void localShow (const std::shared_ptr<CNode<T>> & ptr)
{
    if (ptr == nullptr) return;
    localShow (ptr->getLC());
    std::cout << ptr->GetData () << std::endl;
    localShow (ptr->getRC());
}


template<typename T>
void BSTree<T>::show () const
{
    localShow (m_Root->getLC());
    std::cout << m_Root->GetData () << std::endl;
    localShow (m_Root->getRC());
}

#endif // BINARYSEARCHTREE_HPP
