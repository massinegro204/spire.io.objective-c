//
//  Session.h
//  Spire
//
//  Created by Jorge Gonzalez on 4/27/12.
//  Copyright (c) 2012 Spire.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SPOperation.h"
#import "SPResource.h"
#import "SPAccount.h"
#import "SPChannels.h"
#import "SPSubscriptions.h"

@interface SPSession : SPResource<SPOperationManager, SPHTTPResponseParser, SPChannelsDelegate>{
    SPOperation *_operation;
    NSArray *_channelList;
    
    SPAccount *_account;
    SPChannels *_channels;
    SPSubscriptions *_subscriptions;
}

@property(nonatomic, readonly) SPAccount *account;
@property(nonatomic, readonly) SPChannels *channels;
@property(nonatomic, readonly) SPSubscriptions *subscriptions;

- (void)retrieveChannels;
- (void)createChannelWithName:(NSString *)name;
- (void)retrieveSubscriptions;
- (void)createSubscriptionWithName:(NSString *)name forChannel:(NSString *)channel;
- (void)createSubscriptionWithName:(NSString *)name forChannels:(NSArray *)channels withExpiration:(NSNumber *)expiration;

@end


@protocol SPSessionDelegate <NSObject>

@optional
- (void)sessionRetrieveChannelsDidFinishWithResponse:(SPHTTPResponse *)response;
- (void)sessionCreateChannelDidFinishWithResponse:(SPHTTPResponse *)response;
- (void)sessionRetrieveSubscriptionDidFinishWithResponse:(SPHTTPResponse *)response;
- (void)sessionCreateSubscriptionDidFinishWithResponse:(SPHTTPResponse *)response;
@end
