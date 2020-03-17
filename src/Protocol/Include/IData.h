/**
 * @file IData.h
 * @author Alexander Najbjerg Christensen (au482141@post.au.dk)
 * @brief Interface for the data class used as communication.
 * @version 0.1
 * @date 2020-03-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef IDATA_H_
#define IDATA_H_

class IData
{
public:
    virtual void getData(char* dataOutputParameter) const = 0;
    virtual void setData(char* dataInputParameter) = 0;
};

#endif // IDATA_H_