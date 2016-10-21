#ifndef POST_PROCESSOR_H
#define POST_PROCESSOR_H

#include <iostream>

namespace seissol
{

namespace writer
{

class PostProcessor {
private:
    int m_tmp;
public:
    PostProcessor ():m_tmp(-1){
    }
    virtual ~PostProcessor () {
        m_tmp = 0;
    }
    void tmpFunc();
};
}
}

#endif // POST_PROCESSOR_H
