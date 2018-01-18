@import Foundation;

/*!
 Informal protocol for view-like objects that can be laid out with YOLayout.
 */
@protocol YOLayoutableView <NSObject>

/*!
 Set the position of this 'view'.

 @param frame CGRect representing the position of this 'view'
 */
- (void)setFrame:(CGRect)frame;

@optional

/*!
 Asks the 'view' to calculate and return the size that best fits the specified size.
 This must be implemented if using this view with the YOLayoutOptionsSizeToFit* set of options.

 @param size Size for which the view should calculate its best-fitting size.
 @result Size that best fits the receiver’s content.
 */
- (CGSize)sizeThatFits:(CGSize)size;

@end
