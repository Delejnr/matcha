// +build matcha,darwin

#ifndef MOCHIGO_OBJC_H
#define MOCHIGO_OBJC_H

#import <Foundation/Foundation.h>
#import "matchaforeign.h"
#import "matchago.h"
@class MatchaGoValue;

@interface MatchaGoBridge : NSObject
+ (MatchaGoBridge *)sharedBridge;
@end

@interface MatchaGoValue : NSObject
- (id)initWithGoRef:(GoRef)ref; // not for external use.
- (id)initWithObject:(id)v;
- (id)initWithBool:(BOOL)v;
- (id)initWithInt:(int)v;
- (id)initWithLongLong:(long long)v;
- (id)initWithUnsignedLongLong:(unsigned long long)v;
- (id)initWithDouble:(double)v;
- (id)initWithString:(NSString *)v;
- (id)initWithData:(NSData *)v;
- (id)initWithArray:(NSArray<MatchaGoValue *> *)v;
- (id)initWithType:(NSString *)typeName;
- (id)initWithFunc:(NSString *)funcName;
@property (nonatomic, readonly) GoRef ref; // not for external use.
- (id)toObject;
- (BOOL)toBool;
- (long long)toLongLong;
- (unsigned long long)toUnsignedLongLong;
- (double)toDouble;
- (NSString *)toString;
- (NSData *)toData;
- (NSArray *)toArray;
- (BOOL)isNil;
- (BOOL)isEqual:(MatchaGoValue *)value;
- (MatchaGoValue *)elem;
- (NSArray<MatchaGoValue *> *)call:(NSString *)method, ... NS_REQUIRES_NIL_TERMINATION; // pass in nil for the method to call a closure. varargs should be of MatchaGoValue *.
- (NSArray<MatchaGoValue *> *)call:(NSString *)method args:(va_list)args; 
- (MatchaGoValue *)field:(NSString *)name;
- (void)setField:(NSString *)name value:(MatchaGoValue *)value;
- (MatchaGoValue *)objectForKeyedSubscript:(NSString *)key;
- (void)setObject:(MatchaGoValue *)object forKeyedSubscript:(NSString *)key;
@end

#endif // MOCHIGO_OBJC_H
