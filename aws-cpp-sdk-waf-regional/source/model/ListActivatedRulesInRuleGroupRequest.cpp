﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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

#include <aws/waf-regional/model/ListActivatedRulesInRuleGroupRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::WAFRegional::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

ListActivatedRulesInRuleGroupRequest::ListActivatedRulesInRuleGroupRequest() : 
    m_ruleGroupIdHasBeenSet(false),
    m_nextMarkerHasBeenSet(false),
    m_limit(0),
    m_limitHasBeenSet(false)
{
}

Aws::String ListActivatedRulesInRuleGroupRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_ruleGroupIdHasBeenSet)
  {
   payload.WithString("RuleGroupId", m_ruleGroupId);

  }

  if(m_nextMarkerHasBeenSet)
  {
   payload.WithString("NextMarker", m_nextMarker);

  }

  if(m_limitHasBeenSet)
  {
   payload.WithInteger("Limit", m_limit);

  }

  return payload.WriteReadable();
}

Aws::Http::HeaderValueCollection ListActivatedRulesInRuleGroupRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "AWSWAF_Regional_20161128.ListActivatedRulesInRuleGroup"));
  return headers;

}




