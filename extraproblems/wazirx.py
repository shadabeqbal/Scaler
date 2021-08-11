import requests as rq
import json

op=rq.get("https://api.wazirx.com/api/v2/tickers")
j=json.loads(op.text)

print(j['shibinr']['open'])