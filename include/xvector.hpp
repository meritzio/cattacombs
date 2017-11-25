#ifndef XVECTOR_HPP
#define XVECTOR_HPP

#include <vector>
#include <stdlib.h>
using namespace std;

namespace cattacombs
{
    template <class T> class xvector : public vector<T>
    {
        public:
            ///Push an element if it's not already in the lise
            bool push_unique(T element)
            {
                int iL = this->size();
                
                for(int i = 0; i < iL; i++)
                    if(this->at(i) == element)
                        return false;
                
                this->push_back(element);
                return true;
            }
            
            ///An erase extension of the vector to look for an element and remove it if exists
            bool remove(T element)
            {
                int iL = this->size();
                
                for(int i = 0; i < iL; i++)
                if(this->at(i) == element) {
                    iL = i;
                    break;
                }
                
                if(iL < this->size()) {
                    this->erase(this->begin() + iL);
                    return true;
                }

                return false;
            }
            
            ///Remove and return the last element
            T dequeue()
            {
                T element = this->back();
                this->pop_back();
                return element;
            }
            
            ///get a random element from the vector
            T random()
            {
                return this->at(rand() % this->size());
            }
    };
}

#endif
