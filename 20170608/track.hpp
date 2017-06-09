#include <iostream>
#include <iomanip>
#include "opencv/cv.h"
#include <math.h>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string.h>
#include <ctime>
#include <assert.h>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv/cvaux.hpp>
#include <algorithm>
#include <cmath>
//#include <caffe/caffe.hpp>
#include <map>
#include "Vector2.hpp"

using namespace cv;
using namespace std;

// ************ Dataset Predefine *********** //
//#define ADL_Rundle_1
//#define ADL_Rundle_3
//#define AVG_TownCentre
//#define KITTI_16
#define KITTI_19
//#define ETH_Crossing
//#define ETH_Jelmoli
//#define ETH_Linthescher
//#define Venice_1
//#define PETS09_S2L2
//#define TUD_Crossing
//#define canteenres
//#define tianmuluv5
//#define zhuangyuange02
//#define test61
//#define street1

#if defined(AVG_TownCentre)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(1920,1080);
string DS = "AVG-TownCentre";
#endif

#if defined(ADL_Rundle_1)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(1920,1080);
string DS = "ADL-Rundle-1";
#endif

#if defined(ADL_Rundle_3)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(1920,1080);
string DS = "ADL-Rundle-3";
#endif

#if defined(Venice_1)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(1920,1080);
string DS = "Venice-1";
#endif

#if defined(KITTI_19)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(1238,374);
string DS = "KITTI-19";
#endif

#if defined(KITTI_16)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(1238,374);
string DS = "KITTI-16";
#endif

#if defined(ETH_Jemoli)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "ETH-Jemoli";
#endif

#if defined(ETH_Crossing)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "ETH-Crossing";
#endif

#if defined(ETH_Linthescher)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "ETH-Linthescher";
#endif

#if defined(TUD_Crossing)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "TUD-Crossing";
#endif

#if defined(tianmuluv5)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "tianmuluv5";
#endif

#if defined(canteenres)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "canteenres";
#endif

#if defined(zhuangyuange02)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "zhuangyuange02";
#endif

#if defined(PETS09_S2L2)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(768,576);
string DS = "PETS09-S2L2";
#endif

#if defined(test61)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "test61";
#endif

#if defined(test8)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "test8";
#endif

#if defined(test7)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "test7";
#endif

#if defined(test6)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "test6";
#endif

#if defined(test5)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "test5";
#endif

#if defined(test4)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "test4";
#endif

#if defined(test3)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "test3";
#endif

#if defined(test2)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "test2";
#endif

#if defined(test1)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "test1";
#endif

#if defined(street1)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "street1";
#endif

#if defined(street1_1)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "street1_1";
#endif

#if defined(street1_2)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "street1_2";
#endif

#if defined(street2)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "street2";
#endif

#if defined(street3)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "street3";
#endif

#if defined(street4)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "street4";
#endif

#if defined(street5)
const CvPoint Border_LeftTop = cvPoint(0,0);
const CvPoint Border_RightDown = cvPoint(640,480);
string DS = "street5";
#endif

/*****************************Sturcture Declaration********************************/

//Detection Structure
class PointVar
{
private:
    bool delet;

public:
    Vector2<double> position;   //t is the center of the detection(width)
    double trust; //Size is the width
    int width, height, frame, id, kind, overlap;
    bool Use;
    double* apfeature;
    int tracklet_id;

public:
    PointVar(const PointVar& pt) 
    {
        position = pt.position;
        trust = pt.trust;
        width = pt.width;
        height = pt.height;
        frame = pt.frame;
        id = pt.id;
        Use = pt.Use;
        apfeature = pt.apfeature;
        tracklet_id = pt.tracklet_id;
    }

    void print()
    {
        std::cout << "Frame: " << frame << " ID: " << id << " x: " 
            <<position.x << " y: " << position.y << " width: " 
            << width << " height: " << height << " confidence: "
            << trust << '\n';
    }

    double* output()
    {
        double* returnvalue = new double[4];
        returnvalue[0] = position.x-width / 2;
        returnvalue[1] = position.y-height / 2;
        returnvalue[2] = width;
        returnvalue[3] = height;
        return returnvalue;
    }

    // This init is for tracking with car and human
    PointVar(int frame1, double x1, double y1, double width1, double height1, 
            int kind1, double trust1, int ID1, double overlap1)
    {
        cv::Point Border_lt = Border_LeftTop;
        cv::Point Border_rd = Border_RightDown;
        tracklet_id = -1;
        frame = frame1;
        id = ID1;
        int row = (int)(y1 + height1 / 2);
        int col =(int)( x1 + width1 / 2);
        position.x = col;
        position.y = row;
        width = (int)width1;
        height = (int)height1;
        kind = kind1;
    	overlap = overlap1;
        trust = trust1;
        Use = false;
        delet = false;
        apfeature = NULL;
        //if(width < 10 || height < 10) delet=true;
        if (! ((int)x1 > Border_lt.x && (int)x1 < Border_rd.x 
                    && (int)y1 > Border_lt.y && (int)y1 < Border_rd.y))
            delet=true;
    }

    // This init is for tracking for only human
    PointVar(int frame1, double x1, double y1, double width1,
            double height1, double trust1, int ID1)
    {
        cv::Point Border_lt = Border_LeftTop;
        cv::Point Border_rd = Border_RightDown;
        tracklet_id = -1;
        frame = frame1;
        id = ID1;
        int row = (int)(y1 + height1 / 2);
        int col =(int)( x1 + width1 / 2);
        position.x = col;
        position.y = row;
        width = (int)width1;
        height = (int)height1;
        kind = 1;
    	overlap = -1;
        trust = trust1;
        Use = false;
        delet = false;
        apfeature = NULL;
        //if(width < 10 || height < 10) delet=true;
        if (! ((int)x1 > Border_lt.x && (int)x1 < Border_rd.x 
                    && (int)y1 > Border_lt.y && (int)y1 < Border_rd.y))
            delet=true;
    }


    PointVar() {}
    ~PointVar() {}

    bool delete_judge()
    {
        return delet;
    }
};

//Edgetype structure
class Edge_type_class{
public:
    int type;
    Vector2<double> pa;

    Edge_type_class(int t1)
    {
        type = t1;
        pa.x = 0;
        pa.y = 0;
    }

    Edge_type_class(int t1, Vector2<double> p1)
    {
        type = t1;
        pa = p1;
    }

    void print()
    {
        cout<<type<<"/"<<pa.x<<"/"<<pa.y<<"\t";
    }
};

//Tracklet Structure
class tracklet{
public:
    int delete_counting; //buffer detection frames
    int printbool;  // indicates whether to print in final results or not
    Vector2<double> velocity;
    vector <PointVar*> storage;
    vector<double> relation;
    vector<Edge_type_class> edgeType;
    vector<double> edgeWeights;
    double lambda1, lambda2;
    int id, realId;
    bool finished_sign;
public:
    //double current_app[1024];
    double area;
    double tracklet_weight;
    tracklet(vector<tracklet>& tracklet_pool, int& tracklet_id);
    tracklet(PointVar *target, vector<tracklet>& tracklet_pool, int& tracklet_id);
    bool operator <(const tracklet& next) const
    {
        return id < next.id;
    }
    //~tracklet();
};

class tmp_sort{
public:
    int index;
    int x;
    tmp_sort(int index1, int x1){
        index = index1;
        x = x1;
    }
    bool operator >(const tmp_sort& Pinfo) const{
        return x>Pinfo.x;
    }
    bool operator <(const tmp_sort& Pinfo) const{
        return x<Pinfo.x;
    }
};

class Endpoint{
public:
    int start, end, id;
    bool pre,next;
    Endpoint(int s, int e,int i, int finalFrame) {
        start = s;
        end = e;
        id = i;
        pre = false;
        next = false;
        if (s == 1) pre = true;
        if (e == finalFrame) next = true;
    }
    Endpoint(){;}
    void Setvalue(int s, int e,int i, int finalFrame) {
        start = s;
        end = e;
        id = i;
        pre = false;
        next = false;
        if (s == 1) pre = true;
        if (e == finalFrame) next = true;
    }
};
class GTnode{
public:
    int frame, x, y, width, height, id;
    GTnode(int a, int b, int c, int d, int e ,int f) {
        frame = a;
        x = b;
        y = c;
        width = d;
        height = e;
        id = f;
    }
};

// The new graph match method
bool Compare(const pair<double, int>& a, const pair<double, int>& b)
{
    return a.first > b.first;
}

class GMSpectrual
{
public:
    GMSpectrual();
    GMSpectrual(int nJt, double dbEps);
    
    /* Interface for the GM method */
    void FinalOut(double** pMatrix, int m, int n, vector<int>& plan);

    void GetResult(double * pMatrix,int nDim, double *pdblVects,
            double *pdbEigenValues, double dbEps,int nJt);
    void ConnectTwoTargets(int idx);
    bool CheckFinished(vector<int>& vec);
    void CalculateAll(map<double, vector<int> >& oneEigenvalueVector);

    /* calculate the eigenvaluse and store in eigenvalue2Vector */
    bool JacbiCor(double* pMatrix,int nDim, double* pdblVects, 
        double*pdbEigenValues, double dbEps, 
        int nJt, /* out */map<double, vector<map<double, vector<int> > > >& eigenvalue2Vector);

private:
    // the algorithm parameters
    int mJt;
    double mDbEps;

    // id to the pair plan
    pair<int, int>* idx2Pairs;
    // mJudge and nJudge are to judge whether the target is connected. if 1, then it is connected
    vector<int> mJudge, nJudge;
    // final plan
    vector<int> finalPlan;
    // origin affinity matrix
    double** affinityMatrix;
}; 

GMSpectrual::GMSpectrual()
{
    mJt = 1000;
    mDbEps = 0.001;
}

GMSpectrual::GMSpectrual(int nJt, double dbEps)
{
    mJt = nJt;
    mDbEps = dbEps;
}

bool GMSpectrual::CheckFinished(vector<int>& vec)
{
    bool vecResult = true;
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == 0)
        {
            vecResult = false;
            break;
        }
    return vecResult;
}

void GMSpectrual::ConnectTwoTargets(int idx)
{
    int pairId1 = idx2Pairs[idx].first, pairId2 = idx2Pairs[idx].second;
    // cout << "id1: " << pairId1 << " id2: " << pairId2 << endl;
    // if 1. affinity matrix indicates not to connect, than force not to connect
    //    2. one of the targets has already connected, than not connect
    if (affinityMatrix[idx][idx] < 0.05 || 
        mJudge[pairId1] == 1 || nJudge[pairId2] == 1)
        return;
    else
    {
        mJudge[pairId1] = 1;
        nJudge[pairId2] = 1;
        finalPlan[pairId1] = pairId2;
    } 
}

void GMSpectrual::CalculateAll(map<double, vector<int> >& oneEigenvalueVector)
{
    map<double, vector<int> >::reverse_iterator it = oneEigenvalueVector.rbegin();
    // cout << "start CalculateAll..." << endl;

    for (; it != oneEigenvalueVector.rend(); it++)
    {
        // if finished than return
        if (CheckFinished(mJudge) || CheckFinished(nJudge))
            return;
        // if content is 0 than return (warning: it->first is double, and has already done fabs())
        if (it->first < 0.000001)
            return;

        if (it->second.size() == 1)
        {
            int idx = it->second[0];
            // cout << "before connect: " << idx << " " << it->first << endl;
            ConnectTwoTargets(idx);
        }
        else
        {
            vector<pair<double, int> > tmpVec;
            for (int i = 0; i < it->second.size(); i++)
            {
                int tmpIdx = it->second[i];
                pair<double, int> tmpPair(affinityMatrix[tmpIdx][tmpIdx], tmpIdx);
                tmpVec.push_back(tmpPair);
            }
            sort(tmpVec.begin(), tmpVec.end(), Compare);

            for (int i = 0; i < tmpVec.size(); i++)
            {
                ConnectTwoTargets(tmpVec[i].second);
            }
        }
    }
}

void mypause(){
    cout<<"Enter to continue...\n";
    cin.get();
}

void GMSpectrual::GetResult(double * pMatrix,int nDim, double *pdblVects, double *pdbEigenValues, double dbEps,int nJt)
{
    map<double, vector<map<double, vector<int> > > > eigenvalue2Vector;
    JacbiCor(pMatrix, nDim, pdblVects, pdbEigenValues, dbEps, nJt, eigenvalue2Vector);
   
    //This loop is to traverse all the eigenvalue and its corresponding vector.
    //VERY IMPORTANT: 0 can not be used in the eigenvalue2Vector.
    map<double, vector<map<double, vector<int> > > >::reverse_iterator rit;
    for (rit = eigenvalue2Vector.rbegin(); rit != eigenvalue2Vector.rend(); rit++)
    {
        // if finished, than break
        if (CheckFinished(mJudge) || CheckFinished(nJudge))
            break;
        // Here need to be very cautious, that the eigenvalue should be all positive for a positive definate matrix.
        // if the eigencalue is 0, than break, because such low value will miss connect two targets.
        if (rit->first < 0.000001)
        {
            break;
        }

        if (rit->second.size() == 1)
        {
            CalculateAll(rit->second[0]);
            /*
            cout << "mJudge: ";
            for (int i = 0; i < mJudge.size(); i++)
                cout << mJudge[i] << " ";
            cout << endl << "nJudge: ";
            for (int j = 0; j < nJudge.size(); j++)
                cout << nJudge[j] << " ";
            cout << endl;
            */
        }
        else // else combine the vector of the same eigenvalue into 1 map
        {
            map<double, vector<int> > allEigenvalueVector = rit->second[0];
            
            // add all map pair to the allEigenvalueVector
            for (int i = 1; i < rit->second.size(); i++)
            {
                map<double, vector<int> >::iterator it4;
                for (it4 = rit->second[i].begin(); it4 != rit->second[i].end(); it4++)
                {
                    map<double, vector<int> >::iterator it5 = allEigenvalueVector.find(it4->first);
                    if (it5 == allEigenvalueVector.end())
                    {
                        allEigenvalueVector.insert(make_pair(it4->first, it4->second));
                    }
                    else
                    {
                        for (int j = 0; j < it4->second.size(); j++)
                        {
                            allEigenvalueVector[it4->first].push_back(it4->second[j]);
                        }
                    }
                }
            }

            CalculateAll(allEigenvalueVector);
        }
    }
}

void GMSpectrual::FinalOut(double** pMatrixInput, int m, int n, std::vector<int>& plan)
{
    int nDim = m * n;
    affinityMatrix = pMatrixInput;
    double* pMatrix = new double[nDim * nDim];
    
    for (int i = 0; i < nDim; i++)
        for (int j = 0; j < nDim; j++)
        {
            pMatrix[i * nDim + j] = pMatrixInput[i][j];
            //cout << pMatrix[i * nDim + j] << " ";
        }
    cout << endl;
  

    idx2Pairs = new pair<int, int>[nDim];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pair<int, int> pTmp(i, j);
            idx2Pairs[i * n + j] = pTmp;
        }
    }
    mJudge.assign(m, 0);
    nJudge.assign(n, 0);
    finalPlan.assign(m, -1);

    double* pdblVects = new double[nDim * nDim];
    double* pdbEigenValues = new double[nDim];
    GetResult(pMatrix, nDim, pdblVects, pdbEigenValues, mDbEps, mJt);
    
    //not use   
    delete []pdblVects;
    delete []pdbEigenValues;

    //use
    delete []idx2Pairs;
    delete []pMatrix;

    //output
    plan = finalPlan;
}

bool GMSpectrual::JacbiCor(double* pMatrix,int nDim, double *pdblVects, double *pdbEigenValues, double dbEps, int nJt, map<double, vector<map<double, vector<int> > > > & eigenvalue2Vector)  
{  
    for(int i = 0; i < nDim; i ++)   
    {     
        pdblVects[i * nDim + i] = 1.0f;   
        for(int j = 0; j < nDim; j ++)   
        {   
            if(i != j)     
                pdblVects[i * nDim + j] = 0.0f;   
        }   
    }   
  
    int nCount = 0;     //迭代次数  
    while(1)  
    {  
        //在pMatrix的非对角线上找到最大元素  
        double dbMax = pMatrix[1];  
        int nRow = 0;  
        int nCol = 1;  
        for (int i = 0; i < nDim; i ++)          //行  
        {  
            for (int j = 0; j < nDim; j ++)      //列  
            {  
                double d = fabs(pMatrix[i * nDim + j]);   
  
                if ((i != j) && (d > dbMax))   
                {   
                    dbMax = d;     
                    nRow = i;     
                    nCol = j;   
                }   
            }  
        }  

        if (dbMax < dbEps)     //精度符合要求   
            break;    
  
        if (nCount > nJt)       //迭代次数超过限制  
            break;  
  
        nCount++;  
  
        double dbApp = pMatrix[nRow*nDim+nRow];  
        double dbApq = pMatrix[nRow*nDim+nCol];  
        double dbAqq = pMatrix[nCol*nDim+nCol];  
  
        //计算旋转角度  
        double dbAngle = 0.5*atan2(-2*dbApq,dbAqq-dbApp);  
        double dbSinTheta = sin(dbAngle);  
        double dbCosTheta = cos(dbAngle);  
        double dbSin2Theta = sin(2*dbAngle);  
        double dbCos2Theta = cos(2*dbAngle);  
  
        pMatrix[nRow*nDim+nRow] = dbApp*dbCosTheta*dbCosTheta +   
            dbAqq*dbSinTheta*dbSinTheta + 2*dbApq*dbCosTheta*dbSinTheta;  
        pMatrix[nCol*nDim+nCol] = dbApp*dbSinTheta*dbSinTheta +   
            dbAqq*dbCosTheta*dbCosTheta - 2*dbApq*dbCosTheta*dbSinTheta;  
        pMatrix[nRow*nDim+nCol] = 0.5*(dbAqq-dbApp)*dbSin2Theta + dbApq*dbCos2Theta;  
        pMatrix[nCol*nDim+nRow] = pMatrix[nRow*nDim+nCol];  
  
        for(int i = 0; i < nDim; i ++)   
        {   
            if((i!=nCol) && (i!=nRow))   
            {   
                int u = i*nDim + nRow;  //p    
                int w = i*nDim + nCol;  //q  
                dbMax = pMatrix[u];   
                pMatrix[u]= pMatrix[w]*dbSinTheta + dbMax*dbCosTheta;   
                pMatrix[w]= pMatrix[w]*dbCosTheta - dbMax*dbSinTheta;   
            }   
        }   
  
        for (int j = 0; j < nDim; j ++)  
        {  
            if((j!=nCol) && (j!=nRow))   
            {   
                int u = nRow*nDim + j;  //p  
                int w = nCol*nDim + j;  //q  
                dbMax = pMatrix[u];   
                pMatrix[u] = pMatrix[w]*dbSinTheta + dbMax*dbCosTheta;   
                pMatrix[w] = pMatrix[w]*dbCosTheta - dbMax*dbSinTheta;   
            }   
        }  
  
        //计算特征向量  
        for(int i = 0; i < nDim; i ++)   
        {   
            int u = i*nDim + nRow;      //p     
            int w = i*nDim + nCol;      //q  
            dbMax = pdblVects[u];   
            pdblVects[u] = pdblVects[w]*dbSinTheta + dbMax*dbCosTheta;   
            pdblVects[w] = pdblVects[w]*dbCosTheta - dbMax*dbSinTheta;   
        }   
  
    }

    // Custom output structure build
    for (int i = 0; i < nDim; i++)
    {
        double eigenvalue = pMatrix[i * nDim + i];
        map<double, vector<map<double, vector<int> > > >::iterator it = eigenvalue2Vector.find(eigenvalue);

        if (it == eigenvalue2Vector.end())
        {
            vector<map<double, vector<int> > > tmpEigenvalue;
            eigenvalue2Vector[eigenvalue] = tmpEigenvalue;
        }

        map<double, vector<int> >  tmp;
        eigenvalue2Vector[eigenvalue].push_back(tmp);
        for (int j = 0; j < nDim; j++)
        {
            double currentEigenvalue = fabs(pdblVects[j * nDim + i]);
            map<double, vector<int> >::iterator it3 = eigenvalue2Vector[eigenvalue].back().find(currentEigenvalue);
            if (it3 == eigenvalue2Vector[eigenvalue].back().end())
            {
                std::vector<int> vTmp;
                eigenvalue2Vector[eigenvalue].back().insert(make_pair(currentEigenvalue, vTmp));            
            }
            eigenvalue2Vector[eigenvalue].back()[currentEigenvalue].push_back(j);
        }
    }

    // 以下部分不需要
    // 对特征值进行排序以及重新排列特征向量,特征值即pMatrix主对角线上的元素  
    std::map<double,int> mapEigen;  
    for(int i = 0; i < nDim; i ++)   
    {     
        pdbEigenValues[i] = pMatrix[i*nDim+i];  
        //cout << "feature: " << pdbEigenValues[i] << endl;
        mapEigen.insert(make_pair( pdbEigenValues[i],i ) );  
    }   
    double *pdbTmpVec = new double[nDim*nDim];  
    std::map<double,int>::reverse_iterator iter = mapEigen.rbegin();  
    for (int j = 0; iter != mapEigen.rend() && j < nDim; ++iter, ++j)  
    {  
        for (int i = 0; i < nDim; i ++)  
        {  
            pdbTmpVec[i*nDim+j] = pdblVects[i*nDim + iter->second];  
        }  
  
        //特征值重新排列  
        pdbEigenValues[j] = iter->first;  
    }  
  
    //设定正负号  
    for(int i = 0; i < nDim; i ++)   
    {  
        double dSumVec = 0;  
        for(int j = 0; j < nDim; j ++)  
            dSumVec += pdbTmpVec[j * nDim + i];  
            //dSumVec += pdblVects[j * nDim + i];  
        if(dSumVec<0)  
        {  
            for(int j = 0; j < nDim; j ++)  
                pdbTmpVec[j * nDim + i] *= -1;  
                //pdblVects[j * nDim + i] *= -1;  
        }  
    }  
    memcpy(pdblVects,pdbTmpVec,sizeof(double)*nDim*nDim);  
    delete []pdbTmpVec;  
  
    return 1;  
}  

class Tracking
{
public:
    std::vector<CvScalar> sVec;
    map<int, int> id2realIdMap;

    //relationship threshold
    double edge_threshold;

    //the parameter for sigmoid function
    double width;
    double translation;

    //all hyph (dont change)
    vector<vector<int> > hyp_all;
    int hyp_all_count;
    int last_numtmp_hyp;

    //max plan
    vector<int> best_plan;

    //max hyp_plan
    double max_hyp_plan;
    vector<int> best_hyp_plan;

    //simiINDEX
    double* simiIndex;
    double* simiEdgeIndex;
    //Variable used in print results, if detections in a tracklet is less than it, not print
    int Delete_Less_Than;

    //buffer of lost in frames
    int GLOBAL_DELETE_BUFFER;
    int OUTPUT_BUFFER;
    int HYPERPLANE_GAP;
    //boundary of the neighbourhood
    int bound;

    //+1 flag
    int complete_flag;

    //motion enable
    int MOTION_ENABLE;

    //tracklet id
    int tracklet_id;
    int REALIDCOUNT;

    //filter enable
    int Filtering_enable;
    
    //motion weight redefine
    double MOTIONWEIGHT;

    //button
    int button;

    int max_plan;

    std::vector<std::vector<PointVar* > > DetectionArray;

    std::vector<tracklet> tracklet_pool;

    std::vector<tracklet> all_tracklet;

    Tracking()
    {
        GetScalar(sVec);

        tracklet_id = 1;

        edge_threshold = 5;
        width = 1;
        translation = 0;

        hyp_all_count = 0;
        last_numtmp_hyp = -1;

        max_hyp_plan = -10000;

        simiIndex = NULL;
        simiEdgeIndex = NULL;

        Delete_Less_Than = 5;
        GLOBAL_DELETE_BUFFER = 7;
        HYPERPLANE_GAP = 10;
        bound = 30;
        complete_flag = 1;
        Filtering_enable = 0;
        MOTION_ENABLE = 1;
        OUTPUT_BUFFER = 20;
        REALIDCOUNT = 1;
		MOTIONWEIGHT = 0.5;

        button = 1; // 0 old; 1 new
    }

    void mypause(){
        cout<<"Enter to continue...\n";
        cin.get();
    }
    
    int ReadMatAllStatic()
    {
        //string DS = Dataset;
        string passp3 = "/img1/";
        string passp4 = "/det/";
        string passp6 = ".avi";
        string passp7 = "feature.txt";

        string passp1 = "/home/sam/Desktop/Xcode_MOT/2DMOT2015/test/";
        //string passp5 = "/home/sam/Desktop/Xcode_MOT/Result_IMGs/";
        string passp5 = "/home/sam/Desktop/Xcode_MOT/Result_Upload_2015/result_private_original_test8/";
        string passp8 = "/home/sam/Desktop/Xcode_MOT/Result_Upload_2015/upload_private_original_test8/";
        const string base_dir = passp1 + DS + passp3;
        const string data_dir = passp1 + DS + passp4;
        const string out_dir = passp5 + DS + passp6;
        const string result_img = passp5 + DS + "/";
        const string feature_dir = passp1 + DS + passp4 + passp7;
        const std::string upload_dir = passp8;
        
        int start = 1;
        int totalFrame = 2000;
        int PicN = start + totalFrame - 1;
        cout << "Checking <base_dir>   : " << base_dir << endl;
        cout<<"Checking <data_dir>   : "<<data_dir<<endl;
        cout<<"Checking <feature_dir>: "<<feature_dir<<endl;

        vector<string> PicArray;
        string Txtname, Listname,Imglist;

        Txtname = data_dir+"data.txt";
        Listname = data_dir+"list.txt";
        Imglist = base_dir + "img_list.txt";
        ifstream fin_data(Txtname.c_str());
        ifstream fin_list(Listname.c_str());
        ifstream fin_imglist(Imglist.c_str());      //preparing path and filename
        int totalframe;     //checking the total frames
        fin_imglist >> totalframe;
        if (PicN > totalframe) {
            cout << "Warning in <main:PicN>: Exceeding Frame!\n";
            PicN = totalframe;
        }

        vector<int> deleteFrame, deleteID;
        for(int i = 0; i < PicN; i++)
        {
            int detection_num, nonsense;
            fin_list >> nonsense >> detection_num;
            string tmpstring;
            fin_imglist >> tmpstring;
            tmpstring = base_dir + tmpstring;
            PicArray.push_back(tmpstring);
            vector<PointVar*> OneDetection;

            for (int j = 0;j < detection_num; j++)
            {
                double x, y, width, height, trust;
                int frame;
                fin_data >> frame >> x >> y >> width >> height >> trust; //detection data in
                PointVar* tmp = new PointVar(frame, x,
                        y, width, height, trust, j);		//construction

                if (!tmp->delete_judge())       // delete some detections
                    OneDetection.push_back(tmp);
                else 
                {
                    deleteFrame.push_back(frame);
                    deleteID.push_back(j);
                }
            }
            DetectionArray.push_back(OneDetection);
        }
        fin_data.close();
        fin_list.close();
        int delete_count = 0;
        ifstream feature(feature_dir.c_str());

        for (int i = 0; i <= int(DetectionArray.size()) - 1 ;i++)
        {
            for (int j = 0; j <= int(DetectionArray[i].size()) - 1; j++)
            {
                if (DetectionArray[i].size() == 0)
                    break;

                double* feature_tmp;
                feature_tmp = new double[1024];
                int checkframe, checkid;
                feature >> checkframe >> checkid;
                if (checkframe == deleteFrame[delete_count] && checkid == deleteID[delete_count]) 
                {
                    j--;
                    delete_count++;
                    for (int i_tp = 0; i_tp <= 1023; i_tp ++){
                        double tmp_wr;
                        feature >> tmp_wr;
                    }
                    continue;
                }
                //checking detection feature index
                if (checkframe != i+1 || checkid != DetectionArray[i][j]->id){
                    cout << "<ERROR in main:reading feature> Detection feature index not matching!\n";
                    cout << "trueframe: " << i + 1 << "\tcheckframe: " << checkframe << endl;
                    cout << "trueid   : " << DetectionArray[i][j]->id << "\tcheckid   : " << checkid << endl;
                    mypause();
                }
                for (int i_tp = 0; i_tp <= 1023; i_tp ++){
                    double writing_tmp;
                    feature >> writing_tmp;
                    feature_tmp[i_tp]=writing_tmp;
                }
                DetectionArray[i][j]->apfeature = feature_tmp;
            }
        }
        return 0;
    }

    void ReadingExam()
    {
        for (int i = 0 ; i <= int(DetectionArray.size()) - 1 ; i ++){
            for (int j = 0; j <= int(DetectionArray[i].size()) - 1 ; j++){
                if (int(DetectionArray[i].size())==0) break;
                DetectionArray[i][j]->print();
            }
            cout<<'\n';
        }
    }

    int ReadMat(int k, Mat& input)
    {
        int detectionCount = input.rows;
        int currentIndex = (int)DetectionArray.size() - 1;
        vector<PointVar*> OneFrameDetection;

        DetectionArray.push_back(OneFrameDetection);

        //printf("num: %i\n", detectionCount);
        //printf("%i %i\n",detectionCount, input.cols);

        if (detectionCount == 1 && input.cols == 1)
        {
            printf("hello\n");
            return 1;
        }
        
        for (int i = 0; i < detectionCount; i ++)
        {
            int frame;
            double x, y, width, height, kind, trust = -1, overlap;
            frame = k;
            x = input.at<double>(i,0);
            y = input.at<double>(i,1);
            width = input.at<double>(i,2) - x;
            height = input.at<double>(i,3) - y;
            kind = input.at<double>(i,4);
	        overlap = input.at<double>(i,1029);
            if (currentIndex != -1 && DetectionArray[currentIndex].size() != 0)
            {
                int nexFrame = DetectionArray[currentIndex][0]->frame;
                if (nexFrame != frame - 1) {
                    cout << "<ERROR in ReadTxt>: frame not match!" << nexFrame << " " << frame << endl;
                    return -1;
                }
            }

            PointVar* tmp;
            tmp = new PointVar(frame, x, y, width, height, kind, trust, i, overlap);
            DetectionArray[currentIndex + 1].push_back(tmp);

            double* featureVector = new double[1024];
            for (int j = 0 ; j < 1024; j ++)
            {
                featureVector[j] = input.at<double>(i, j + 5) / 1000;
            }
            DetectionArray[currentIndex + 1][i]->apfeature = featureVector;
        }
        return 0;
    }

    void UpdateTrackletID(int currentFrame, vector<PointVar*>& FrameOutput)
    {
        if (currentFrame < OUTPUT_BUFFER) return;
        for (int i = 0; i < all_tracklet.size(); i ++)
        {
            // 1. update realid
            if (all_tracklet[i].realId == -1 && all_tracklet[i].storage.size() >= Delete_Less_Than)
            	all_tracklet[i].realId = REALIDCOUNT ++;

            // 2. update pointvar id
            if (all_tracklet[i].finished_sign == 0)
            {
                int startFrame = all_tracklet[i].storage[0]->frame;
                int endFrame = (int)all_tracklet[i].storage.size() + startFrame - 1;
                if (endFrame < startFrame + Delete_Less_Than)
                {
                    all_tracklet[i].finished_sign = 1;
                    continue;
                }
                
                int outputFrame = currentFrame - OUTPUT_BUFFER;
                int indexFrame = outputFrame - startFrame;
                
                if (indexFrame < 0 || indexFrame >= all_tracklet[i].storage.size())
                    continue;
                
                all_tracklet[i].storage[indexFrame]->tracklet_id = all_tracklet[i].realId;
                if (all_tracklet[i].storage.size() >= 7 && indexFrame >= 3 && indexFrame < int(all_tracklet[i].storage.size()) - 3) {
                    double xTmp = 0, yTmp = 0, wTmp = 0, hTmp = 0;
                    for (int q = -3; q <= 3 ; q ++) {
                        xTmp += all_tracklet[i].storage[indexFrame + q]->position.x;
                        yTmp += all_tracklet[i].storage[indexFrame + q]->position.y;
                        wTmp += all_tracklet[i].storage[indexFrame + q]->width;
                        hTmp += all_tracklet[i].storage[indexFrame + q]->height;
                    }
                    all_tracklet[i].storage[indexFrame]->position.x = int( xTmp / 7 );
                    all_tracklet[i].storage[indexFrame]->position.y = int( yTmp / 7 );
                    all_tracklet[i].storage[indexFrame]->width = int( wTmp / 7 );
                    all_tracklet[i].storage[indexFrame]->height = int( hTmp / 7 );
                    //cout << int( xTmp / 7 ) << int( yTmp / 7 ) << int( wTmp / 7 ) << int( hTmp / 7 );
                }
                FrameOutput.push_back(all_tracklet[i].storage[indexFrame]);
                if (indexFrame == all_tracklet[i].storage.size() - 1) {
                    all_tracklet[i].finished_sign = 1;
                }
            }
        }
        
        for (int i = 0; i < tracklet_pool.size(); i ++)
        {
        	// 1. update realid
            if (tracklet_pool[i].realId == -1 && tracklet_pool[i].storage.size() >= Delete_Less_Than)
            	tracklet_pool[i].realId = REALIDCOUNT ++;
            int outputFrame = currentFrame - OUTPUT_BUFFER;
            int indexFrame = outputFrame - tracklet_pool[i].storage[0]->frame;
            
            if (indexFrame >= 0 && indexFrame < tracklet_pool[i].storage.size())
            {
                tracklet_pool[i].storage[indexFrame]->tracklet_id = tracklet_pool[i].realId;
                if (tracklet_pool[i].storage.size() >= 7 && indexFrame >= 3 && indexFrame < int(tracklet_pool[i].storage.size()) - 3) {
                    double xTmp = 0, yTmp = 0, wTmp = 0, hTmp = 0;
                    for (int q = -3; q <= 3 ; q ++) {
                        xTmp += tracklet_pool[i].storage[indexFrame + q]->position.x;
                        yTmp += tracklet_pool[i].storage[indexFrame + q]->position.y;
                        wTmp += tracklet_pool[i].storage[indexFrame + q]->width;
                        hTmp += tracklet_pool[i].storage[indexFrame + q]->height;
                    }
                    tracklet_pool[i].storage[indexFrame]->position.x = int( xTmp / 7 );
                    tracklet_pool[i].storage[indexFrame]->position.y = int( yTmp / 7 );
                    tracklet_pool[i].storage[indexFrame]->width = int( wTmp / 7 );
                    tracklet_pool[i].storage[indexFrame]->height = int( hTmp / 7 );
                }
                FrameOutput.push_back(tracklet_pool[i].storage[indexFrame]);
            }
        }
    }

    int drawOneFrame(vector<PointVar*>& TrackedDetection, Mat& src, int currentFrame, vector<CvScalar> &sVec)
    {
       	std::stringstream ss;
       	std::string FrameIndex;
       	ss << currentFrame + 1;
       	ss >> FrameIndex;    // frame index
       
       	putText(src, FrameIndex, Point(100, 100), CV_FONT_HERSHEY_COMPLEX, 2, Scalar(0, 0, 255));
       	int framesize = (int) TrackedDetection.size();
       	for (int i=0;i<framesize;i++){
         	int x,y,width,height,index;
           	width = TrackedDetection[i]->width;
           	height = TrackedDetection[i]->height;
           	x = TrackedDetection[i]->position.x - width / 2;
           	y = TrackedDetection[i]->position.y - height / 2;
           	index = TrackedDetection[i]->tracklet_id;
           
           	Rect r;
           	r.x = x;
           	r.y = y;
           	r.width = width;
           	r.height = height;
           
           	Point t2;
           	t2.x = x;
           	t2.y = y;
           
           	CvScalar s = sVec[index % int(sVec.size())];
           	rectangle(src, r, s,1);
           	string typee = " CP";
           	std::stringstream ss;
           	ss << index << typee[TrackedDetection[i]->kind];
	   		if (TrackedDetection[i]->overlap == 1) ss << "*";
           		std::string strIndex;
           	ss >> strIndex;
           
           	putText(src, strIndex, t2, CV_FONT_HERSHEY_SIMPLEX, 0.8, s);     //draw index
       	}
       
		string result_img = "/home/sam/Desktop/Xcode_MOT/Result_IMGs/" + DS + '/';
        string out_dir_new=result_img + NumToString2(currentFrame+1) + ".jpg";

        imwrite(out_dir_new, src);
       // imshow("outWindow",src);
       // cvWaitKey(1);
    }

    string NumToString2(int i) {
        stringstream s;
        s << i;
        return s.str();
    }

    void GetScalar(std::vector<CvScalar> &sVec)
    {
        sVec.push_back(cvScalar(0,0,255));
        sVec.push_back(cvScalar(255,0,0));
        sVec.push_back(cvScalar(0,255,0));
        sVec.push_back(cvScalar(255,0,255));
        sVec.push_back(cvScalar(0,255,255));
        sVec.push_back(cvScalar(255,255,0));
        sVec.push_back(cvScalar(128,0,255));
        sVec.push_back(cvScalar(0,128,255));
        sVec.push_back(cvScalar(128,255,0));
        sVec.push_back(cvScalar(0,255,128));
        sVec.push_back(cvScalar(255,128,0));
        sVec.push_back(cvScalar(255,0,128));
        sVec.push_back(cvScalar(128,128,255));
        sVec.push_back(cvScalar(128,255,128));
        sVec.push_back(cvScalar(255,128,128));
    }

    void global_push(tracklet &tmp){
        for (int i = 0; i < (int)tracklet_pool.size(); ++i)
        {
            //It is reasonable to assume there is no reltion between two targets without evidence
            tracklet_pool[i].relation.push_back(0);
            Edge_type_class tmp1(-1);
            tracklet_pool[i].edgeType.push_back(tmp1);
            //cout<<tracklet_pool.size()<<"\t"<<tracklet_pool[i].edgeType.size()<<endl;
            tracklet_pool[i].edgeWeights.push_back(1);
        }

        tracklet_pool.push_back(tmp);
    }

    int global_delete(int k){
        if (++tracklet_pool[k].delete_counting > GLOBAL_DELETE_BUFFER ){
            all_tracklet.push_back(tracklet_pool[k]);
            for (int i = 0; i < (int)tracklet_pool.size(); ++i){
                if ((int)tracklet_pool.size()==0) break;
                vector<double>:: iterator iter=tracklet_pool[i].relation.begin();
                iter += k;
                tracklet_pool[i].relation.erase(iter);
                
                vector<Edge_type_class>:: iterator iter1=tracklet_pool[i].edgeType.begin();
                iter1 += k;
                tracklet_pool[i].edgeType.erase(iter1);
                
                vector<double>:: iterator iter2=tracklet_pool[i].edgeWeights.begin();
                iter2 += k;
                tracklet_pool[i].edgeWeights.erase(iter2);
            }
            vector<tracklet>::iterator iter3=tracklet_pool.begin();
            iter3+=k;
            tracklet_pool.erase(iter3);
            return 1;
        }
        else return 0;
    }

    void generate_best_plan(vector<vector<int> > &candidate,vector<int> &plan,vector<int> one_to_one,int trackletID){
        generate_all_possibility2(candidate, 0, plan, one_to_one, trackletID);
    }

    void generate_all_possibility2(vector<vector<int> > &candidate,
                                   int pos, vector<int> &plan, vector<int> one_to_one, int trackletID)
    {
        //bool flag=false;
        if (pos>=(int)candidate.size()) {
            double obj_current = compute_gain(DetectionArray[trackletID],plan, candidate,trackletID,simiIndex);
            if (obj_current > max_plan){
                best_plan = plan;
                max_plan = obj_current;
            }
            //hyp_all.push_back(plan);
            return;
        }

        for (int i = 0; i < candidate[pos].size(); i ++) {
            if (candidate[pos][i] == -1 || one_to_one[candidate[pos][i]] != 0) {
                plan[pos] = -1;
                generate_all_possibility2(candidate, pos + 1, plan, one_to_one, trackletID);
            }
            else if (one_to_one[candidate[pos][i]] == 0){
                plan[pos] = candidate[pos][i];
                one_to_one[candidate[pos][i]]=1;
                generate_all_possibility2(candidate, pos+1, plan, one_to_one,trackletID);
                one_to_one[candidate[pos][i]]=0;
            }
            else {
                mypause();
            }
        }
        
        return;
    }

    double compute_gain(std::vector<PointVar*> &detection,vector<int> &plan,
                    vector<vector<int> > &candidate, int frame,double* simiIndex)
    {
        double gain = 0;
        int size = (int)tracklet_pool.size();
        //double lambda;
        PointVar* target_tmp, *target_tmp2, *target1_track2, *target2_track2;
        //PointVar* target1,*target2,*target3,*target4;
        
        //compute the node gain
        for (int i = 0; i < size; ++i)
        {
            if (plan[i]!=-1){
                target_tmp=tracklet_pool[i].storage.back();
                target_tmp2=detection[plan[i]];
                //double tmp1=target_tmp->position.x;
                //double tmp2=target_tmp2->position.x;
                
                //double debug_gain = simiIndex[i*(int(detection.size()))+plan[i]];
                gain+=simiIndex[i*(int(detection.size()))+plan[i]];
                
                double tmp_gain = 0;
                int tmp_counting = 0;
                //Edge similarity
                for (int j = 0 ; j < i; j ++) {
                    if (tracklet_pool[i].edgeType[j].type != -1 && plan[j] != -1) {
                        Edge_type_class type = tracklet_pool[i].edgeType[j];
                        target1_track2=tracklet_pool[j].storage.back();
                        target2_track2=detection[plan[j]];
                        
                        double tmp_return = compute_distance_variation_version2(target_tmp, target_tmp2, target1_track2,target2_track2, type);
                        if (tmp_return != -2) {
                            if (button == 1)
                                tmp_gain += tmp_return;// * tracklet_pool[i].edgeWeights[j];
                            else
                                tmp_gain += tmp_return * tracklet_pool[i].edgeWeights[j];

                            tmp_counting ++;
                        }
                    }
                }
                if (tmp_counting != 0){
                    tmp_counting = 1;
                    gain += tmp_gain / tmp_counting;
                }
            }
        }     
        return gain;
    }

    double compute_distance_variation_version2(const PointVar *tracklet1_a,const PointVar *tracklet1_b,const PointVar *tracklet2_a,const PointVar *tracklet2_b, Edge_type_class Edge)
    {
        double angle_difference, length_difference;
        //double distance1,distance2;
        Vector2<double> previous = tracklet1_a->position - tracklet2_a->position;
        Vector2<double> current = tracklet1_b->position - tracklet2_b->position;
        Vector2<double> various = Edge.pa;
        if (Edge.type == 2 || Edge.type == 3){
            previous = previous + various;
        }
        angle_difference = Vector2<double>::dotProduct(previous,current)/(previous.absolute()*current.absolute());
        if (angle_difference >= 1)
        {
            angle_difference = 0.9999;
        }
        if (angle_difference <= -1)
        {
            angle_difference = -0.9999;
        }
        double angle = acos(angle_difference);
        length_difference = current.absolute() - previous.absolute();
        //angle_difference = 1 / 2.0 * angle_difference + 1 / 2.0;
        //1 group, 0 occlusion, 2 getting closer, 3 getting away
        double tmp_gain;
        double denu = (tracklet1_a->width + tracklet2_a->width)/2;
        if (Edge.type == 1){
            tmp_gain = exp(-abs(length_difference)/(denu)) * exp(-abs(angle)*3);
        }
        else if (Edge.type == 0){
            tmp_gain = -2;
            return tmp_gain;
        }
        else if (Edge.type == 2){
            if (length_difference <= 0){
                tmp_gain = exp(-abs(length_difference)/(denu)) * exp(-abs(angle)*3);
            }
            else
                tmp_gain = exp(-abs(length_difference)/(denu)) * exp(-abs(angle)*3);
        }
        else if (Edge.type == 3){
            if (length_difference >= 0)
                tmp_gain = exp(-abs(length_difference)/(denu)) * exp(-abs(angle)*3);
            else
                tmp_gain = exp(-abs(length_difference)/(denu)) * exp(-abs(angle)*3);
        }
        
        if (tmp_gain < 0.1) {
            return -1;
        }
        //cout << "ld: " << length_difference << " denu: " << denu << " angle: " << angle << " ad: " << angle_difference << endl;
        //cout << "tmp_gain: " << tmp_gain << endl;
        return tmp_gain;
    }

    double correlation_node(tracklet& track, PointVar* candidate)
    {
        int size;
        PointVar* tmp;
        double simi_motion,result,simi_app;

        size=(int)track.storage.size();
        tmp=track.storage[size-1];
        
        simi_motion=correlation_motion(&track,candidate);
        
        simi_app=CoAppearance(track, candidate);
        
        if (MOTION_ENABLE == 1){
            //result = track.lambda1 * simi_motion + track.lambda2 * simi_app;
            result = MOTIONWEIGHT * simi_motion + (1 - MOTIONWEIGHT) * simi_app;
        }
        else if (MOTION_ENABLE ==0){
            result = simi_app;
        }

        return result;
    }

    double correlation_motion(tracklet *track,PointVar *candidate)
    {
        if ((int)track->storage.size() < 4) return 0;
        double result;
        Vector2<double> vector1,vector2,velocity,velocity_dif;
        PointVar* tmp;
        int scale = 0;
        velocity=track->velocity;
        scale=(int)track->storage.size();
        tmp=track->storage[scale-3];
        vector1=tmp->position;
        Vector2<double> p1 = track->storage[scale-4]->position;
        Vector2<double> p2 = track->storage[scale-2]->position;
        
        p1 = vector1 + (p1 - vector1)/(track->storage[scale-3]->frame - track->storage[scale-4]->frame);
        p2 = vector1 + (p2 - vector1)/(track->storage[scale-2]->frame - track->storage[scale-3]->frame);
        vector1 = (p1 + p2 + vector1)/3.0;
        vector2 = candidate->position;
        vector2 = (vector2-vector1)/(candidate->frame-tmp->frame);
        velocity_dif = vector2 - velocity;
        if (velocity.absolute() == 0 || vector2.absolute() == 0)
            result = 0;
        else
        {
            double angle_dif = Vector2<double>::dotProduct(velocity,vector2)/(velocity.absolute()*vector2.absolute());
            double length_difference = abs(velocity.absolute() - vector2.absolute());
            double denu = (track->storage[scale-1]->width + candidate->width)/2;
            double angle_difference = acos(angle_dif);
            result = exp(-abs(angle_difference)*3) * exp(-abs(length_difference)/(denu));
        }
        if (button == 0)
            result = result * track->tracklet_weight;
        return result;
    }

    double CoAppearance(tracklet& pre,PointVar* next)
    {
        double totalsum = 0;
        double sum1 = 0,sum2 = 0;
        double *preap, *nextap;
        int trackletsize = (int)pre.storage.size();
        preap = pre.storage[trackletsize-1]->apfeature;

        nextap = next->apfeature;
        for (int i=0 ; i < 1024 ; i ++){
            totalsum += preap[i] * nextap[i];
            sum1 += preap[i]*preap[i];
            sum2 += nextap[i]*nextap[i];
            //totalsum += (preap[i] - nextap[i]) * (preap[i] - nextap[i]);
        }
        //totalsum /= 1024;
        //cout << "denu: " << sum1*sum2 << endl;
        totalsum /= sqrt(sum1*sum2);
        double angle_difference = acos(totalsum);
        double tmp_return = exp(-abs(angle_difference)*3);

        if (button == 0)
            tmp_return *= pre.tracklet_weight;
        return tmp_return;
    }

    void add_P2T(tracklet *track, PointVar *newdetection){
        if (track->storage.size() == 0) {
            track->storage.push_back(newdetection);
            update_velocity(track);
            return;
        }
        int currentFrame = newdetection->frame;
        
        int lastFrame = track->storage[track->storage.size() - 1]->frame;
        if (lastFrame + 1 == currentFrame) {
            track->storage.push_back(newdetection);
            update_velocity(track);
        }  
        else {
            int frame1 = track->storage[track->storage.size() - 1]->frame;
            int frame2 = newdetection->frame;
            double width1 = track->storage[track->storage.size() - 1]->width;
            double height1 = track->storage[track->storage.size() - 1]->height;
            double x1 = track->storage[track->storage.size() - 1]->position.x - width1/2;
            double y1 = track->storage[track->storage.size() - 1]->position.y - height1/2;
            double width2 = newdetection->width;
            double height2 = newdetection->height;
            double x2 = newdetection->position.x - width2/2;
            double y2 = newdetection->position.y - height2/2;
            for (int q = 0; q < frame2-frame1-1; q++) 
            {
                // This is init for the both car and human
                //PointVar* tmp1 = new PointVar( frame1 + q + 1, 
                //        (x2 - x1) / (frame2 - frame1) * (q + 1) + x1,
                //        (y2 - y1) / (frame2 - frame1) * (q + 1) + y1,
                //        (width2 - width1) / (frame2 - frame1) * (q + 1) + width1,
                //        (height2 - height1) / (frame2 - frame1) * (q + 1) + height1,
                //        track->storage[track->storage.size() - 1]->kind, 
                //        -1, -1, newdetection->overlap);
                PointVar* tmp1 = new PointVar( frame1 + q + 1, 
                        (x2 - x1) / (frame2 - frame1) * (q + 1) + x1,
                        (y2 - y1) / (frame2 - frame1) * (q + 1) + y1,
                        (width2 - width1) / (frame2 - frame1) * (q + 1) + width1,
                        (height2 - height1) / (frame2 - frame1) * (q + 1) + height1,
                        -1, -1);
                track->storage.push_back(tmp1);
            }
            track->storage.push_back(newdetection);
            update_velocity(track);
        }
    }

    void update_edge_node_weight(std::vector<tracklet> &tracklet_pool,std::vector<PointVar*> &detection){
        int size=(int)tracklet_pool.size();
        PointVar* target_tmp, *target_tmp2, *target1_track2, *target2_track2;
        
        //compute the node gain
        for (int i = 0; i < size; ++i){
            if (best_plan[i] == -1){
                tracklet_pool[i].tracklet_weight /= 1.1;
                for (int j = 0; j < i; j ++ ) {
                    if (tracklet_pool[i].edgeType[j].type != -1){
                        tracklet_pool[i].edgeWeights[j] /= 1.1;
                        tracklet_pool[j].edgeWeights[i] /= 1.1;
                    }
                }
            }
            else if (best_plan[i]!= -1){
                target_tmp=tracklet_pool[i].storage.back();
                target_tmp2=detection[best_plan[i]];
                
                //Node similarity calculation (using index to speed up)!
                double appearance_similaruty = simiIndex[i*(int(detection.size()))+best_plan[i]];
                //cout<<"appearance_similaruty: "<<appearance_similaruty<<endl;
                tracklet_pool[i].tracklet_weight = sigmoid(tracklet_pool[i].tracklet_weight - 1 + (appearance_similaruty - 0.2) * 5, 0, -1,2);
                //Edge similarity
                for (int j = 0 ; j < i; j ++) {
                    if (tracklet_pool[i].edgeType[j].type != -1 && best_plan[j] != -1) {
                        int type = tracklet_pool[i].edgeType[j].type;
                        target1_track2=tracklet_pool[j].storage.back();
                        target2_track2=detection[best_plan[j]];
                        double edge_similarity = compute_distance_variation_version2(target_tmp, target_tmp2, target1_track2,target2_track2, type);
                        if (edge_similarity != -2){
                            tracklet_pool[i].edgeWeights[j] = sigmoid(tracklet_pool[i].edgeWeights[j] - 1 + (edge_similarity - 0.5) * 5, 0, -1,2);
                            tracklet_pool[j].edgeWeights[i] = tracklet_pool[i].edgeWeights[j];
                        }
                    }
                    else if (tracklet_pool[i].edgeType[j].type != -1 && best_plan[j] == -1) {
                        tracklet_pool[i].edgeWeights[j] /= 1.1;
                        tracklet_pool[j].edgeWeights[i] /= 1.1;
                    }
                }
            }
        }
    }

    void update_relation(std::vector<tracklet> &tracklet_pool){
        //need to check
        PointVar* target1;
        PointVar* target2;
        PointVar* target3;
        PointVar* target4;
        
        int num1,num2;
        
        double correlation=0;
        
        int scale=(int)tracklet_pool.size();
        for (int i = 0; i < scale; ++i){
            for (int j = 0; j < i; ++j){
                num1=(int)tracklet_pool[i].storage.size();
                num2=(int)tracklet_pool[j].storage.size();
                if (num1>=2 && num2>=2){
                    target1=tracklet_pool[i].storage[num1-2];
                    target2=tracklet_pool[i].storage[num1-1];
                    target3=tracklet_pool[j].storage[num2-2];
                    target4=tracklet_pool[j].storage[num2-1];
                    correlation=compute_distance_variation(target1,target2,target3,target4);
                    
                    if (correlation>=edge_threshold){
                        tracklet_pool[i].relation[j]-=1;
                        tracklet_pool[j].relation[i]-=1;
                    }
                    else{
                        tracklet_pool[i].relation[j]+=1;
                        tracklet_pool[j].relation[i]+=1;
                    }
                }
                else
                    return;
            }
        }
        return;
    }
	double compute_distance_variation(const PointVar *tracklet1_a,const PointVar *tracklet1_b,const PointVar *tracklet2_a,const PointVar *tracklet2_b){
		double difference;
		//double distance1,distance2;
		Vector2<double> previous=tracklet1_a->position-tracklet2_a->position;
		Vector2<double> current=tracklet1_b->position-tracklet2_b->position;
		difference = Vector2<double>::dotProduct(previous,current)/(previous.absolute()*current.absolute());
		return difference;
	}
    void update_edgetype(std::vector<tracklet> &tracklet_pool,int frame){
        int scale=(int)tracklet_pool.size();
        int num1, num2, frame1, frame2;
        if (scale == 0) return;
        for (int i = 0; i <= scale - 1; i++){
            for (int j = 0; j <= i - 1; j++){
                num1=(int)tracklet_pool[i].storage.size();
                num2=(int)tracklet_pool[j].storage.size();
                Vector2<double> speed1, speed2, location1, location2;
                double width1, height1, width2, height2;
                speed1 = tracklet_pool[i].velocity;
                speed2 = tracklet_pool[j].velocity;
                frame1 = tracklet_pool[i].storage[num1-1]->frame;
                frame2 = tracklet_pool[j].storage[num2-1]->frame;
                location1 = tracklet_pool[i].storage[num1-1]->position;
                location2 = tracklet_pool[j].storage[num2-1]->position;
                width1 = tracklet_pool[i].storage[num1-1]->width;
                height1 = tracklet_pool[i].storage[num1-1]->height;
                width2 = tracklet_pool[j].storage[num2-1]->width;
                height2 = tracklet_pool[j].storage[num2-1]->height;
                if (tracklet_pool[i].velocity.absolute() == 0 || tracklet_pool[j].velocity.absolute() == 0){
                    if (abs(location1.x - location2.x) < (width1 + width2)*1 && abs(location1.y - location2.y) <(width1+width2)*1){
                        tracklet_pool[i].edgeType[j].type = 1;
                        tracklet_pool[j].edgeType[i].type = 1;
                        continue;
                    }
                    tracklet_pool[i].edgeType[j].type = -1;
                    tracklet_pool[j].edgeType[i].type = -1;
                    continue;
                }

                if (num1 >= 2 && num1>=2){
                    double speed_variation = Vector2<double>::dotProduct(speed1, speed2)/(speed2.absolute() * speed1.absolute());
                    double speed_abs_va = abs(speed1.absolute() / speed2.absolute());
                    Vector2<double> relative_velcity = speed1 - speed2;
                    Vector2<double> relative_position = location2 - location1;
                    double oreantation = Vector2<double>::dotProduct(relative_velcity, relative_position)/(relative_velcity.absolute() * relative_position.absolute());
                    // -1 not connected, 1 group, 0 occlusion, 2 getting closer, 3 getting away
                    if (abs(location1.x - location2.x) < (width1 + width2) * 1.5 && abs(location1.y - location2.y) <(width1+width2)*1.5 && speed_variation >= 0.75 && speed_abs_va <= 1.5 && speed_abs_va >= 0.67) {
                        tracklet_pool[i].edgeType[j].type = 1;
                        tracklet_pool[j].edgeType[i].type = 1;
                    }
                    else if(abs(location1.x - location2.x) < (width1 + width2)/2 && abs(location1.y - location2.y) <(width1+width2)/2 && tracklet_pool[i].edgeType[j].type == 2){
                        tracklet_pool[i].edgeType[j].type = 1;
                        tracklet_pool[j].edgeType[i].type = 1;
                    }
                    else if(abs(location1.x - location2.x) < (width1 + width2) * 3 && abs(location1.y - location2.y) <(width1 + width2) * 3 /*&& speed_variation <= -0.8*/ && oreantation >= 0.5 && tracklet_pool[i].edgeType[j].type != 3){
                        tracklet_pool[i].edgeType[j].type = 2;
                        tracklet_pool[j].edgeType[i].type = 2;
                        tracklet_pool[i].edgeType[j].pa = speed1 * (frame - frame1 + 1) - speed2 * (frame - frame2 + 1);
                        tracklet_pool[j].edgeType[i].pa = speed2 * (frame - frame2 + 1) - speed1 * (frame - frame1 + 1);
                    }
                    else if(abs(location1.x - location2.x) < (width1 + width2) * 3 && abs(location1.y - location2.y) <(width1 + width2) * 3 /*&& speed_variation <= -0.8*/ && oreantation <= -0.5){
                        tracklet_pool[i].edgeType[j].type = 3;
                        tracklet_pool[j].edgeType[i].type = 3;
                        tracklet_pool[i].edgeType[j].pa = speed1 * (frame - frame1 + 1) - speed2 * (frame - frame2 + 1);
                        tracklet_pool[j].edgeType[i].pa = speed2 * (frame - frame2 + 1) - speed1 * (frame - frame1 + 1);
                    }
                    else if(abs(location1.x - location2.x) >= (width1 + width2) * 2){
                        tracklet_pool[i].edgeType[j].type = -1;
                        tracklet_pool[j].edgeType[i].type = -1;
                    }
                }
                else {
                    tracklet_pool[i].edgeType[j].type = -1;
                    tracklet_pool[j].edgeType[i].type = -1;
                }
            }
        }
    }

    void update_velocity(tracklet *track){
        int size=(int)track->storage.size();
        if (size <= 6) return;
        if (size <= 6) {
            track->velocity = (track->storage[size-1]->position - track->storage[0]->position) / (track->storage[size-1]->frame - track->storage[0]->frame);
            return;
        }
        Vector2<double> position_queue[6];
        position_queue[0] = track->storage[size-1]->position;//1
        position_queue[1] = track->storage[size-2]->position;//2
        position_queue[2] = track->storage[size-3]->position;//3
        position_queue[3] = track->storage[size-4]->position;//4
        position_queue[4] = track->storage[size-5]->position;//5
        position_queue[5] = track->storage[size-6]->position;//6
        
        position_queue[0] = position_queue[1] + (position_queue[0] - position_queue[1])/(track->storage[size-1]->frame - track->storage[size-2]->frame);
        position_queue[2] = position_queue[1] + (position_queue[2] - position_queue[1])/(track->storage[size-2]->frame - track->storage[size-3]->frame);
        position_queue[3] = position_queue[4] + (position_queue[3] - position_queue[4])/(track->storage[size-3]->frame - track->storage[size-4]->frame);
        position_queue[5] = position_queue[4] + (position_queue[5] - position_queue[4])/(track->storage[size-4]->frame - track->storage[size-5]->frame);
        
        
        track->velocity=((position_queue[0]+position_queue[1]+position_queue[2])/3.0-(position_queue[3]+position_queue[4]+position_queue[5])/3.0)/(track->storage[size-2]->frame-track->storage[size-5]->frame);
        //cout<<track->velocity<<endl;
        return;
    }

	double sigmoid(double x,double a,double b,double c){
	    double denominator;
	    denominator=1+exp((x-a)/b);
	    return c/denominator;
	}

    vector<PointVar *> trackOneFrame(int i/*,  Mat& res*/){
        //ReadMat(i, res);

        //mypause();
        vector<int> optimal_hype;
        int target_num = (int)DetectionArray[i].size();
        int tracklet_num = (int)tracklet_pool.size();
        bool *target_link_flag;
        int difference = 0;
        vector<int> plan;
        vector<int> one_to_one;
        printf("num %i %i\n",target_num, tracklet_num);
       // if (target_num == 0) continue;

        target_link_flag=new bool[target_num];
        for (int p = 0; p < target_num; ++p)
        {
            target_link_flag[p] = 0;
        }

        vector<vector<int> > candidate;
        candidate.assign(tracklet_num, vector<int>(0, 0));
        double all_can = 1;
        //generate candidates that are in the window
        if (complete_flag == 1) {
            for (int m = 0; m < tracklet_num; m ++) {
                candidate[m].push_back(-1);
            }
        }

        int* judgeList = new int[tracklet_num * target_num];
        for (int m = 0; m < tracklet_num * target_num; m++)
        {
            judgeList[m] = 0;
        }

        for (int m=0; m<tracklet_num; m++) {
            PointVar *tmp=tracklet_pool[m].storage.back();
            int dele_count = tracklet_pool[m].delete_counting;
            
            for (int n = 0; n < target_num; n++) {
                double area1 = double(DetectionArray[i][n]->width * DetectionArray[i][n]->height);
                double area2 = tmp->width * tmp->height;
				double sscale[3] = {1, 0.7, 1};
                if (
                     (abs(DetectionArray[i][n]->position.x - tmp->position.x) < tmp->width * sscale[tmp->kind])
                     && (abs(DetectionArray[i][n]->position.y - tmp->position.y) < tmp->width * sscale[tmp->kind])
                     && (area1 / area2 > 0.333333 && area1 / area2 < 3)
                     && (DetectionArray[i][n]->kind == tmp->kind)
                )
                {
                    candidate[m].push_back(n);
                    judgeList[m * target_num + n] = 1;
                }
            }
           // cout << (candidate[m].size()) << " ";
            all_can *= (candidate[m].size());
        }
       // cout << "end" << endl; 

        cout << all_can << " " << tracklet_num << " " << target_num << endl << endl;
        plan.assign(tracklet_num, -1);
        one_to_one.assign(target_num, 0);
        //hyp_all.assign(0,vector<int>(tracklet_num,-1));
        
        simiIndex = new double [target_num * tracklet_num];
        for (int t1 = 0; t1 < tracklet_num; t1 ++){
            for (int t2 = 0; t2 < target_num; t2 ++){
                simiIndex [ t1 * target_num + t2] = correlation_node(tracklet_pool[t1], DetectionArray[i][t2]);
            }
        }

        //start new graph match
        double** affinityMatrix;
        int affinityMatrixSize = tracklet_num * target_num;
        affinityMatrix = new double* [affinityMatrixSize];
        for (int t1 = 0; t1 < affinityMatrixSize; t1++)
        {
            affinityMatrix[t1] = new double[affinityMatrixSize];
            for (int t2 = 0; t2 < affinityMatrixSize; t2++)
                affinityMatrix[t1][t2] = 0;
        }

        int tmpCount = 0;
        for (int t1 = 0; t1 < tracklet_num; t1++)
            for (int t2 = 0; t2 < target_num; t2++)
            {
                if (judgeList[t1 * target_num + t2] == 0)
                {
                    tmpCount++;
                    continue;
                }
                affinityMatrix[tmpCount][tmpCount] = correlation_node(tracklet_pool[t1], DetectionArray[i][t2]);
                //cout << tmpCount << " " << t1 << " " << t2 << endl;
                tmpCount++;
            }

        delete [] judgeList;
        for (int t1 = 0; t1 < tracklet_num; t1++)
            for (int t2 = 0; t2 < target_num; t2++)
                for (int k1 = 0; k1 < tracklet_num; k1++)
                    for (int k2 = 0; k2 < target_num; k2++)
                    {
                        if (t1 * tracklet_num + t2 == k1 * target_num + k2)
                            continue;
                        if (t1 == k1 || t2 == k2)
                            continue;

                        PointVar *poolFirst, *poolSecond, *detectionFirst, *detectionSecond;
                        poolFirst = tracklet_pool[t1].storage.back();
                        poolSecond = tracklet_pool[k1].storage.back();
                        detectionFirst = DetectionArray[i][t2];
                        detectionSecond = DetectionArray[i][k2];

                        Edge_type_class type = tracklet_pool[t1].edgeType[k1];

                        double tmpEdgeScore = compute_distance_variation_version2(poolFirst, detectionFirst, poolSecond, detectionSecond, type);
                        if (tmpEdgeScore < 0)
                            tmpEdgeScore = 0;
                        tmpEdgeScore *= tracklet_pool[t1].edgeWeights[k1];
                        affinityMatrix[t1 * target_num + t2][k1 * target_num + k2] = tmpEdgeScore / 10;
                        //affinityMatrix[t1 * target_num + t2][k1 * target_num + k2] = 0;                    
                    }
        
        /*
        cout << "AM: \n";
        for (int k = 0; k < affinityMatrixSize; k++)
        {
            for (int q = 0; q < affinityMatrixSize; q++)
            {
                cout << affinityMatrix[k][q] << " ";
            }
            cout << endl;
        }
        */

        if (button == 1)
        {
            GMSpectrual gMSpectrualMethod;
            gMSpectrualMethod.FinalOut(affinityMatrix, tracklet_num, target_num, plan);
            vector<int> GMSpectrualPlan = plan;
            best_plan = plan;
            optimal_hype = GMSpectrualPlan;
        }
        else if (button == 0)
        {
            plan.assign(tracklet_num, -1);
            max_plan = -10000;
            generate_best_plan(candidate, plan, one_to_one, i);
            vector<int> allMPlan = best_plan;
            optimal_hype = best_plan;
        }

        cout << "PlanNew: ";
        for (int l =0 ; l < optimal_hype.size(); l++) {
           cout << optimal_hype[l] << " ";
        }
        cout << endl;

        update_edge_node_weight(tracklet_pool, DetectionArray[i]);
        
        delete [] simiIndex;
        for (int k = 0; k < tracklet_num; ++k)
        {
            if (optimal_hype[k]!=-1){
                target_link_flag[optimal_hype[k]]=1;
                //DetectionArray[i][optimal_hype[k]]->print();
                //mypause();
                add_P2T(&(tracklet_pool[k-difference]), DetectionArray[i][optimal_hype[k]] );
                tracklet_pool[k-difference].delete_counting = 0;
            }
            else{
                int tmp=global_delete(k - difference);
                if (tmp == 1)
                    difference++;
            }
        }

        update_relation(tracklet_pool);
        
        for (int q = 0; q < target_num; ++q)
        {
            if (target_link_flag[q]==0)
            {
                tracklet tmp(DetectionArray[i][q], tracklet_pool, tracklet_id);
                global_push(tmp);
            }
        }
        delete []target_link_flag;
        
        update_edgetype(tracklet_pool, i + 1);
        
        vector<PointVar *> FrameOutput;
        if (DetectionArray.size() <= OUTPUT_BUFFER)
            return FrameOutput;

        UpdateTrackletID(i + 1, FrameOutput);

        for (int q = 0; q < FrameOutput.size(); q ++)
        {
           cout <<FrameOutput[q]->frame << "\t" <<FrameOutput[q]->position << "\t" << FrameOutput[q]->width << "\t" <<FrameOutput[q]->height << "\t" << FrameOutput[q]->tracklet_id <<endl;
        }
        std::stringstream ss;
        if (i >= OUTPUT_BUFFER)
        {
            ss << i + 1 - OUTPUT_BUFFER;
            string impath;
            ss >> impath;
            impath = "./detection/" + impath + ".jpg";
            Mat image = imread(impath);
            drawOneFrame(FrameOutput, image, i + 1 - OUTPUT_BUFFER, sVec);
            return FrameOutput;
        }
    }
};

tracklet::tracklet(vector<tracklet>& tracklet_pool, int& tracklet_id){
    velocity=0; lambda1=0.5; lambda2=0.5; delete_counting=0;
    printbool=1; tracklet_weight=1;
    relation.resize((int)(tracklet_pool.size())+1,0);
    Edge_type_class tmp(-1);
    edgeType.resize(int(tracklet_pool.size())+1,tmp);
    edgeWeights.resize(int(tracklet_pool.size())+1,1);
    id = tracklet_id ++;
    realId = -1;
    tracklet_weight = 1;
    finished_sign = 0;
}

tracklet::tracklet(PointVar *target, vector<tracklet>& tracklet_pool, int& tracklet_id):velocity(0),lambda1(0.5),lambda2(0.5)
{
    storage.push_back(target);
    delete_counting=0;
    printbool=1;
    relation.resize(int(tracklet_pool.size())+1,0);
    Edge_type_class tmp(-1);
    edgeType.resize(int(tracklet_pool.size())+1,tmp);
    edgeWeights.resize(int(tracklet_pool.size())+1,1);
    area = double(target->height * target->width);
    tracklet_weight = 1;
    id = tracklet_id ++;
    realId = -1;
    finished_sign = 0;
}
