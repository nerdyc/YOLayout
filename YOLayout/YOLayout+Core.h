#import "YOLayoutOptions.h"

@import Foundation;
@import CoreGraphics;
@class YOLayout;

/*!
 Block containing logic to layout or size the current view, with the specified
 size as a hint. Return the size used.

 You should never setFrame on subviews in this block. Instead use the methods
 in layout in order to setFrame, and use what those methods return to layout other
 subviews. This is because setFrame calls are no-ops when the view is only sizing.

 @param layout Layout
 @param size Size to layout in
 @result Size of the view being laid out
 */
typedef CGSize (^YOLayoutBlock)(YOLayout * _Nonnull layout, CGSize size);


/*!
 YOLayout is a way to size and layout views without having to implement layoutSubview and
 sizeToFit separately.

 It also provides a basic cache to avoid layout when the view is unchanged.

 YOLayout calculates a size that best fits the receiver’s subviews,
 without altering the subviews frames, or affecting layoutSubviews call hierarchy.

 Instead of defining both sizeThatFits: and layoutSubviews, you create a block named layoutBlock.
 In this block you use the layout instance to set the subview frames (if sizing).

 This prevents your code from altering subviews when you are sizing (for sizeThatFits:).

 For example,

 CGRect titleLabelFrame = [layout setFrame:CGRectMake(x, y, 400, 0) view:_titleLabel options:YOLayoutOptionsSizeToFit];
 // titleLabelFrame may have a different width and will have a valid height

 You can combine YOLayoutOptionsSizeToFit and YOLayoutOptionsCenter to have it be centered with a variable height.
 For example,

 CGRect titleLabelFrame = [layout setFrame:CGRectMake(x, y, 400, 0) view:_titleLabel options:YOLayoutOptionsSizeToFit|YOLayoutOptionsCenter];
 // titleLabelFrame may have a different width and will have a valid height and will have an x position so it is centered

 You can also combine YOLayoutOptionsSizeToFit with YOLayoutOptionsConstraintWidth
 to make sure the width isn't set larger than expected. For example,

 CGRect titleLabelFrame = [layout setFrame:CGRectMake(x, y, 400, 0) view:_titleLabel options:YOLayoutOptionsSizeToFit|YOLayoutOptionsConstraintWidth];
 // titleLabelFrame may have a different width but it won't be larger than 400

 You can combine YOLayoutOptionsSizeToFit, YOLayoutOptionsConstraintWidth, and YOLayoutOptionsDefaultWidth to make sure
 a view sizes to fit with max and default width (when 0).
 */
@interface YOLayout : NSObject

/*!
 Whether the current layout instance is just sizing or setting frames.

 Useful for determining whether to set state that's related to the layout, such as layer.cornerRadius

 @result YES if we are only sizing, NO if we are setting frames
 */
@property (readonly, getter=isSizing) BOOL sizing;

/*!
 Initialize a YOLayout instance.

 @param layoutBlock Block containing layout code. See the discussion above the YOLayoutBlock typedef for more info.
 @result Layout
 */
+ (YOLayout * _Nonnull)layoutWithLayoutBlock:(YOLayoutBlock _Nonnull)layoutBlock;

#pragma mark - Subview Layout Methods

/*!
 Set frame for the (sub)view.
 If we are only sizing, this doesn't modify views frame.

 @param frame Frame
 @param view View object that implements setFrame:
 */
- (CGRect)setFrame:(CGRect)frame view:(id _Nonnull)view;

/*!
 Set the (sub)view frame.
 If we are only sizing, this doesn't modify views frame.

 @param frame Frame
 @param view View object that implements setFrame:
 @param options Options for setFrame; See YOLayoutOptions for more info
 @result The view frame.
 */
- (CGRect)setFrame:(CGRect)frame view:(id _Nonnull)view options:(YOLayoutOptions)options;

/*!
 Set (sub)view size in rect with options.

 @param size Desired size (or size hint if using YOLayoutOptionsSizeToFit)
 @param inRect Rect in which to position the view. `inRect.size` may be different than `size` when using this method with YOLayoutOptionsAlignCenter, YOLayoutOptionsAlignCenterVertical, YOLayoutOptionsAlignRight, etc.
 @param view View object that implements setFrame:
 @param options Options See YOLayoutOptions for more info
 @result The view frame.
 */
- (CGRect)setSize:(CGSize)size inRect:(CGRect)inRect view:(id _Nonnull)view options:(YOLayoutOptions)options;

#pragma mark - Localization

+ (void)setIsRTLEnvironment:(BOOL)isRTLEnvironment;

@end

