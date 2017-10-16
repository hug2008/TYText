//
//  TYTextRender.h
//  TYTextKitDemo
//
//  Created by tany on 2017/9/26.
//  Copyright © 2017年 tany. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSAttributedString+TYTextKit.h"
#import "TYTextStorage.h"
#import "TYTextAttachment.h"
#import "TYTextAttribute.h"
#import "TYLayoutManager.h"

NS_ASSUME_NONNULL_BEGIN
@interface TYTextRender : NSObject

// textkit
@property (nonatomic, strong, nullable) NSTextStorage *textStorage;
@property (nonatomic, strong, readonly) NSLayoutManager *layoutManager;
@property (nonatomic, strong, readonly) NSTextContainer *textContainer;

/**
 text is inset within line fragment rectangles.default 0
 */
@property (nonatomic, assign) CGFloat lineFragmentPadding;
// only support TYLayoutManager. default 4.0
@property (nonatomic, assign) CGFloat highlightBackgroundCornerRadius;

/**
 text attributed contain attach views or layers
 */
@property (nonatomic, strong, readonly, nullable) NSArray *attachments;
//@property (nonatomic, strong, readonly, nullable) NSSet *attachmentSet;
/**
 default YES, otherwise get textStorage'attachViews every time.
 */
@property (nonatomic, assign) BOOL onlySetTextStorageWillGetAttachViews;
/**
 render size
 */
@property (nonatomic, assign) CGSize size;

/**
 visible text bound
 @discussion if size is zero, it return zero
 */
@property (nonatomic, assign, readonly) CGRect textBound;

/**
 text rect in container
 @discussion when text did render,will have value
 */
@property (nonatomic, assign, readonly) CGRect textRect;

- (instancetype)initWithAttributedText:(NSAttributedString *)attributedText;
- (instancetype)initWithTextStorage:(NSTextStorage *)textStorage;
- (instancetype)initWithTextContainer:(NSTextContainer *)textContainer;

/**
 visible text range
 */
- (NSRange)visibleCharacterRange;

/**
 text bound for character range
 */
- (CGRect)boundingRectForCharacterRange:(NSRange)characterRange;

/**
 text character index at piont
 */
- (NSInteger)characterIndexForPoint:(CGPoint)point;

/**
 set text highlight
 */
- (void)setTextHighlight:(TYTextHighlight *)textHighlight range:(NSRange)range;

/**
 draw text at point
 */
- (void)drawTextAtPoint:(CGPoint)point;
- (void)drawTextAtPoint:(CGPoint)point isCanceled:(BOOL (^__nullable)(void))isCanceled;

@end
NS_ASSUME_NONNULL_END
