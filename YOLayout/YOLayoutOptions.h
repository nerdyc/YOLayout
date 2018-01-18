@import Foundation;

typedef NS_OPTIONS (NSUInteger, YOLayoutOptions) {
    YOLayoutOptionsNone = 0,

    // SIZING
    //! Size the view to fit vertically
    YOLayoutOptionsSizeToFitVertical = 1 << 0,
    //! Size the view to fit horizontally
    YOLayoutOptionsSizeToFitHorizontal = 1 << 1,
    //! Size the view to fit both horizontally and vertically
    YOLayoutOptionsSizeToFit = YOLayoutOptionsSizeToFitVertical | YOLayoutOptionsSizeToFitHorizontal,

    /*!
     Constrain sizeThatFit's width to the passed in frame.

     For example, UILabel sizeThatFits: may return a larger width than was specified, and this will constrain it.
     */
    YOLayoutOptionsConstrainWidth = 1 << 2,
    //! Constrain sizeThatFit's height to the passed in frame
    YOLayoutOptionsConstrainHeight = 1 << 3,
    //! Constrain sizeThatFit's height and width
    YOLayoutOptionsConstrainSize = YOLayoutOptionsConstrainWidth | YOLayoutOptionsConstrainHeight,

    /*!
     Constrain sizeThatFits to the size specified but maintain the original aspect ratio.

     This is useful for an image view that may need to be constrained to a max size, but still maintain its aspect ratio.
     */
    YOLayoutOptionsConstrainSizeMaintainAspectRatio = 1 << 4,

    //! Whether the height specified is the default. Using this option will use the specified height when sizeThatFits: returns a 0 height.
    YOLayoutOptionsDefaultHeight = 1 << 5,
    //! Whether the width specified is the default. Using this option will use the specified width when sizeThatFits: returns a 0 width.
    YOLayoutOptionsDefaultWidth = 1 << 6,
    /*!
     Whether the size specified is the default. Using this option will use the specified width and/or height when sizeThatFits: returns a 0 width and/or height, respectively.

     This is useful for an image view that has to load its data and may initially return 0 for sizeThatFits.
     */
    YOLayoutOptionsDefaultSize = YOLayoutOptionsDefaultHeight | YOLayoutOptionsDefaultWidth,

    // ALIGNMENT
    //! After sizing, center vertically in the passed in rect
    YOLayoutOptionsAlignCenterVertical = 1 << 10,
    //! After sizing, center horizontally in the passed in rect
    YOLayoutOptionsAlignCenterHorizontal = 1 << 11,
    //! After sizing, center vertically and horizontally in the passed in rect
    YOLayoutOptionsAlignCenter = YOLayoutOptionsAlignCenterVertical | YOLayoutOptionsAlignCenterHorizontal,
    //! After sizing, aligns the view with the right of the passed in rect
    YOLayoutOptionsAlignRight = 1 << 12,
    //! After sizing, aligns the view with the bottom of the passed in rect
    YOLayoutOptionsAlignBottom = 1 << 13,

    // INTERNATIONALIZATION
    /*!
     After sizing and positioning, potentially flip the x value of a subview for a right-to-left layout when setting frame.

     Subview layout methods (e.g. setFrame:view:options) will continue to return the unflipped frame in order to simplify layout math. The flipped frame, however, will be applied when setting the subview's frame.

     This uses the width of the superview to determine how to flip views, avoiding the need to pass in a separate containerWidth parameter.
     */
    YOLayoutOptionsFlipIfNeededForRTL = 1 << 14,

    // ROUNDING
    //! After sizing and positioning, don't round to the nearest pixel. By default YOLayout uses the screen's scale to round to the nearest pixel.
    YOLayoutOptionsDisablePixelRounding = 1 << 15,
};
