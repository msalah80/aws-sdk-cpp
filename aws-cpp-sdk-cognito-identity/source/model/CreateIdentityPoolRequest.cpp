/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/cognito-identity/model/CreateIdentityPoolRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::CognitoIdentity::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

CreateIdentityPoolRequest::CreateIdentityPoolRequest() : 
    m_identityPoolNameHasBeenSet(false),
    m_allowUnauthenticatedIdentities(false),
    m_allowUnauthenticatedIdentitiesHasBeenSet(false),
    m_supportedLoginProvidersHasBeenSet(false),
    m_developerProviderNameHasBeenSet(false),
    m_openIdConnectProviderARNsHasBeenSet(false)
{
}

Aws::String CreateIdentityPoolRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_identityPoolNameHasBeenSet)
  {
   payload.WithString("IdentityPoolName", m_identityPoolName);

  }

  if(m_allowUnauthenticatedIdentitiesHasBeenSet)
  {
   payload.WithBool("AllowUnauthenticatedIdentities", m_allowUnauthenticatedIdentities);

  }

  if(m_supportedLoginProvidersHasBeenSet)
  {
   JsonValue supportedLoginProvidersJsonMap;
   for(auto& supportedLoginProvidersItem : m_supportedLoginProviders)
   {
     supportedLoginProvidersJsonMap.WithString(supportedLoginProvidersItem.first, supportedLoginProvidersItem.second);
   }
   payload.WithObject("SupportedLoginProviders", std::move(supportedLoginProvidersJsonMap));

  }

  if(m_developerProviderNameHasBeenSet)
  {
   payload.WithString("DeveloperProviderName", m_developerProviderName);

  }

  if(m_openIdConnectProviderARNsHasBeenSet)
  {
   Array<JsonValue> openIdConnectProviderARNsJsonList(m_openIdConnectProviderARNs.size());
   for(unsigned openIdConnectProviderARNsIndex = 0; openIdConnectProviderARNsIndex < openIdConnectProviderARNsJsonList.GetLength(); ++openIdConnectProviderARNsIndex)
   {
     openIdConnectProviderARNsJsonList[openIdConnectProviderARNsIndex].AsString(m_openIdConnectProviderARNs[openIdConnectProviderARNsIndex]);
   }
   payload.WithArray("OpenIdConnectProviderARNs", std::move(openIdConnectProviderARNsJsonList));

  }

  return payload.WriteReadable();
}

Aws::Http::HeaderValueCollection CreateIdentityPoolRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "AWSCognitoIdentityService.CreateIdentityPool"));
  return headers;

}


