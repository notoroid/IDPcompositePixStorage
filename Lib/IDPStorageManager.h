//
//  IDPStorageManager.h
//  ImageUploadTest
//
//  Created by 能登 要 on 2015/07/07.
//  Copyright (c) 2015年 Irimasu Densan Planning. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PFObject;
@class AFHTTPRequestOperation;

@interface IDPStorageManager : NSObject

+ (IDPStorageManager *) defaultManager;

- (void) storeWithImage:(UIImage *)image filename:(NSString *)filename completion:(void (^)(PFObject *photoImage,NSError *error))completion progress:(void (^)(NSUInteger bytesWritten, long long totalBytesWritten, long long totalBytesExpectedToWrite))progress;

- (void) storeWithImage:(UIImage *)image filename:(NSString *)filename completion:(void (^)(PFObject *photoImage,NSError *error))completion;

- (void) cancelAllStore;

- (void) loadImageWithPhotoImage:(PFObject *)photoImage startBlock:(void (^)(AFHTTPRequestOperation *operation))startBlock completion:(void (^)(UIImage *image,NSError *error))completion;

- (void) loadImageWithObjectID:(NSString *)objectID startBlock:(void (^)(AFHTTPRequestOperation *operation))startBlock completion:(void (^)(UIImage *image,NSError *error))completion;


- (void) cancelAllLoad;


@end
