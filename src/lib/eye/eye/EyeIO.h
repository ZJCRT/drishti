/*!
  @file   EyeIO.h
  @author David Hirvonen
  @brief  Declaration of internal routines related to eye model conversion.

  \copyright Copyright 2014-2016 Elucideye, Inc. All rights reserved.
  \license{This project is released under the 3 Clause BSD License.}

  This file contains declarations of various routines related to instantiating
  and converting eye model structures.

*/

#ifndef drishti_eyeio_h
#define drishti_eyeio_h

#include "eye/drishti_eye.h"
#include "eye/Eye.h"
#include "core/Shape.h"

DRISHTI_EYE_BEGIN

struct EyeModelSpecification
{
    static EyeModelSpecification create
    (
        int eyelidCount = 8,
        int creaseCount = 5,
        bool irisCenter = true,
        bool irisOuter = true,
        bool irisInner = true,
        bool irisEllipse = true,
        bool pupilEllipse = true
    );

    cv::Range eyelids;
    cv::Range crease;
    cv::Range irisCenter;
    cv::Range irisOuter;
    cv::Range irisInner;
    cv::Range irisEllipse;
    cv::Range pupilEllipse;
};

EyeModel shapeToEye(const std::vector<cv::Point2f> &points, const EyeModelSpecification &spec);

std::vector<cv::Point2f> eyeToShape(const EyeModel &eye, const EyeModelSpecification &spec);
std::vector<float> eyeToVector(const EyeModel &eye, bool crease=true);
std::vector<float> pointsToVector(const std::vector<cv::Point2f> &points);
std::vector<float>& cat(std::vector<float> &src, const std::vector<float> &params);

DRISHTI_EYE_END

#endif // drishti_eye_serialization_h