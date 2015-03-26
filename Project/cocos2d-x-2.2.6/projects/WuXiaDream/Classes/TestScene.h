//
//  TestScene.h
//  WuXiaDream
//
//  Created by 何金 北京 on 15/3/26.
//
//

#ifndef __WuXiaDream__TestScene__
#define __WuXiaDream__TestScene__
#include "Common.h"
#include <stdio.h>
class TestScene : public CCLayer
{
public:
    static CCScene* scene();
    CREATE_FUNC(TestScene);
    bool init();
    
};
#endif /* defined(__WuXiaDream__TestScene__) */
