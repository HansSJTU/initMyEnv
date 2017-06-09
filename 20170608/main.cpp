/*
 * main.cpp
 * Copyright (C) 2017-06-08 Hanxiao <hah114@ucsd.edu>
 *
 * Distributed under terms of the MIT license.
 */

#include "track.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Tracking tracker;
    tracker.ReadMatAllStatic();
    //tracker.ReadingExam();
    
    for (int i = 0; i < tracker.DetectionArray.size(); i++)
    {
        tracker.trackOneFrame(i);
    }
    
    return 0;
}
