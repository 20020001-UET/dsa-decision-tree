/*
 * This file is part of dsa-decision-tree
 *
 * Developed for the DSA UET course.
 * This project was developed by Ba Luong and Gia Linh.
 */

#pragma once
#ifndef SPLIT_DATA_H
#define SPLIT_DATA_H

#include "Data.h"
#include "CostCalc.h"
#include "BitMask.h"
#include <math.h>

using namespace std;

namespace SplitData
{
    enum SPLIT_VAL
    {
        NONE = -1,
        ATTRIBUTE,
        COMPARISON,
        COMBINATION,
        SPLIT_TOTAL
    };

    SPLIT_VAL getSplitValue(int index);
    SPLIT_VAL randSplit(int rMin = ATTRIBUTE, int rMax = COMBINATION);

    struct GroupSplitData
    {
        GroupDataSet *group;
        double costIndex;
        int attribute;
        int compareValue;
        SPLIT_VAL method;

        GroupSplitData(double cost = 2.0, int atr = -1, int com = -1, SPLIT_VAL met = NONE, GroupDataSet *groupData = NULL);
        ~GroupSplitData();
    };

    namespace Attribute
    {
        // Compare function
        bool compare(Data *data, int atr, int value);

        // Split a dataset based on an attribute and attribute value (equal to atr)
        GroupDataSet *split(DataSet *data, int atr, int value);

        // Split a dataset based on an attribute to a group of two new datasets
        // and select the best split point!
        GroupSplitData getSplit(DataSet *data, int atr);

        vector<int> getErrorIndex(DataSet *data, int atr, int value);
    }

    namespace Comparison
    {
        // Compare function
        bool compare(Data *data, int atr, int value);

        // Split a dataset based on an attribute and attribute value (less to atr)
        GroupDataSet *split(DataSet *data, int atr, int value);

        // Split a dataset based on comparing attribute to a group of two new datasets
        // and select the best split point!
        GroupSplitData getSplit(DataSet *data, int atr);

        vector<int> getErrorIndex(DataSet *data, int atr, int value);

    }

    namespace Combination
    {
        // Compare function
        bool compare(Data *data, int atr, int mask);

        // Split a dataset based on a combination of attribute value
        //  mask is the combinatino bit mask of the value
        GroupDataSet *split(DataSet *data, int atr, int mask);

        // Split a dataset based on a combination of attribute value
        //  to a group of two new datasets and select the best split point!
        GroupSplitData getSplit(DataSet *data, int atr);

        vector<int> getErrorIndex(DataSet *data, int atr, int value);

    }
}

#endif