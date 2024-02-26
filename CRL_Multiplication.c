#include "CRL_Multiplication.h"

void MyAdd_CUSTOM_ROW(const double *u1, const double *u2, double *y1, unsigned int u1_first,
        unsigned int u1_second, unsigned int u2_first, unsigned int u2_second)
{
    unsigned int i,j,k;
    k = 1;/*unused*/
    if (u1_first!=u2_first || u1_second!=u2_second)
    {
        return;
    }
    for (i =0; i<u1_first;i++)
    {
        for (j=0;j<u2_second;j++)
        {
            y1[i*u2_second + j] = 0;
        }
    }
    for (i=0;i<u1_first;i++)
    {
        for (j=0;j<u2_second;j++)
        {
            y1[i*u2_second + j] = u1[i*u1_second+j] + u2[i*u2_second+j];
        }
    }
}

void MyElemMul_CUSTOM_ROW(const double *u1, const double *u2, double *y1, unsigned int u1_first,
        unsigned int u1_second, unsigned int u2_first, unsigned int u2_second)
{
    unsigned int i,j,k;
    k = 1;/*unused*/
    if (u1_first!=u2_first || u1_second!=u2_second)
    {
        return;
    }
    for (i =0; i<u1_first;i++)
    {
        for (j=0;j<u2_second;j++)
        {
            y1[i*u2_second + j] = 0;
        }
    }
    for (i=0;i<u1_first;i++)
    {
        for (j=0;j<u2_second;j++)
        {
            y1[i*u2_second + j] = u1[i*u1_second+j] * u2[i*u2_second+j];
        }
    }
}

void MyMul_CUSTOM_ROW(const double *u1, const double *u2, double *y1, unsigned int u1_first,
        unsigned int u1_second, unsigned int u2_first, unsigned int u2_second)
{
    unsigned int i,j,k;
    for (i =0; i<u1_first;i++)
    {
        for (j=0;j<u2_second;j++)
        {
            y1[i*u2_second + j] = 0;
        }
    }
    for (i=0;i<u1_first;i++)
    {
        for (j=0;j<u2_second;j++)
        {
            for (k=0;k<u1_second;k++)
            {
                /*y1 size: row=u1_first, col=u2_second*/
                y1[i*u2_second + j] += u1[i*u1_second + k]*u2[k*u2_second +j];
            }
        }
    }
}

void MyAdd_CUSTOM_COL(const double *u1, const double *u2, double *y1, unsigned int u1_first,
        unsigned int u1_second, unsigned int u2_first, unsigned int u2_second)
{
    unsigned int i,j,k;
    k = 1;/*unused*/
    if (u1_first!=u2_first || u1_second!=u2_second)
    {
        return;
    }
        
    for (i =0; i<u1_first;i++)
    {
        for (j=0;j<u2_second;j++)
        {
            y1[i+j*u2_first] = 0;
        }
    }
    
    for (i=0;i<u1_first;i++)
    {
        for (j=0;j<u2_second;j++)
        {
            y1[i+j*u2_first] = u1[i+j*u1_first]+ u2[i+j*u2_first];
        }
    }
}

void MyElemMul_CUSTOM_COL(const double *u1, const double *u2, double *y1, unsigned int u1_first,
        unsigned int u1_second, unsigned int u2_first, unsigned int u2_second)
{
    unsigned int i,j,k;
    
    k = 1;/*unused*/
    if (u1_first!=u2_first || u1_second!=u2_second)
    {
        return;
    }
    for (i =0; i<u1_first;i++)
    {
        for (j=0;j<u2_second;j++)
        {
            y1[i+j*u2_first] = 0;
        }
    }
    
    for (i=0;i<u1_first;i++)
    {
        for (j=0;j<u2_second;j++)
        {
            y1[i+j*u2_first] = u1[i+j*u1_first]* u2[i+j*u2_first];
        }
    }
}

void MyMul_CUSTOM_COL(const double *u1, const double *u2, double *y1, unsigned int u1_first,
        unsigned int u1_second, unsigned int u2_first, unsigned int u2_second)
{
    unsigned int i,j,k;
    for (i =0; i<u1_first;i++)
    {
        for (j=0;j<u2_second;j++)
        {
            y1[i+j*u1_first] = 0;
        }
    }
    for (i=0;i<u1_first;i++)
    {
        for (j=0;j<u2_second;j++)
        {
            for (k=0;k<u1_second;k++)
            {
                /*y1 size: row=u1_first, col=u2_second*/
                y1[i+j*u1_first] += u1[i+k*u1_first]*u2[k+j*u2_first];
            }
        }
    }
}