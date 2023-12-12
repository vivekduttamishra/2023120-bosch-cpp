#pragma once

namespace conceptarchitect
{
    namespace collections
    {

        class IndexError
        {
            const string message;
            int index;
        public:
            IndexError(string message,int index)
            {
                this->message=message;
                this->index=index;
            }

            string what()const;
            int where() const;
        };
    }
}



