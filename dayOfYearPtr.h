#include "dayOfYear.h"
namespace SehyunKu2693015
{
    class dayOfYearPtr
    {
        dayOfYear* dPtr;
        public:
        dayOfYearPtr(const dayOfYear& d = dayOfYear(1,1))
        :dPtr(new dayOfYear{d}){}
        ~dayOfYearPtr(){delete dPtr;}
        dayOfYearPtr(const dayOfYearPtr& copy){
            dPtr = copy.dPtr ? new dayOfYear{ *copy.dPtr } : nullptr;
        }
        dayOfYearPtr(dayOfYearPtr&& move) noexcept {
            std::cout << "move constructor\n";
            dPtr = move.dPtr;
            move.dPtr = nullptr;
        }
        dayOfYearPtr& operator=(const dayOfYearPtr& copy) noexcept
        {
            if(this != &copy ){
                delete dPtr;
                dPtr = copy.dPtr ? new dayOfYear{ *copy.dPtr } : nullptr;
            }
            return *this;
        }
        dayOfYearPtr& operator=(dayOfYearPtr&& move) noexcept
        {
            std::cout << "move constructor\n";
            if (this != &move)
            {
                delete dPtr;
                dPtr = move.dPtr;
                move.dPtr = nullptr;
            }
            return *this;
        }
        void print() const
        {
            if (dPtr) std::cout << *dPtr;
            else std::cout << "no data(nullptr)\n";
        }
    };
}