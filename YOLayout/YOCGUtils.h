//
//  YOCGUtils.h
//  YOLayout
//
//  Created by Gabriel Handford on 10/29/13.
//  Copyright (c) 2014 YOLayout. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#if !TARGET_OS_IPHONE

typedef struct UIEdgeInsets {
    CGFloat top, left, bottom, right;
} UIEdgeInsets;

extern const UIEdgeInsets UIEdgeInsetsZero;

static inline UIEdgeInsets UIEdgeInsetsMake(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right) {
    UIEdgeInsets insets = {top, left, bottom, right};
    return insets;
}

static inline UIEdgeInsets UIEdgeInsetsAdd(UIEdgeInsets i1, UIEdgeInsets i2) {
    return UIEdgeInsetsMake(i1.top + i2.top, i1.left + i2.left, i1.bottom + i2.bottom, i1.right + i2.right);
}
#else

#import <UIKit/UIKit.h>

#endif


CGPoint YOCGPointToCenterX(CGSize size, CGSize inSize);

CGPoint YOCGPointToCenterY(CGSize size, CGSize inSize);

BOOL YOCGSizeIsEqual(CGSize size1, CGSize size2);

BOOL YOCGRectIsEqual(CGRect rect1, CGRect rect2);

CGRect YOCGRectSetY(CGRect rect, CGFloat y);

NSString *YONSStringFromCGRect(CGRect rect);

NSString *YONSStringFromCGSize(CGSize size);

CGRect YOCGRectApplyInsets(CGRect frame, UIEdgeInsets insets);
