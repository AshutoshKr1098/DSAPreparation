import requests
import json
cert_file_path = "/root/virt/latest_code/UBB_PKI_Service_API/certs/restuser-july11.pem"
key_file_path = "/root/virt/latest_code/UBB_PKI_Service_API/certs/restuser-july11.key"
ca_cert="/root/virt/latest_code/UBB_PKI_Service_API/certs/HughesIssuingCA-chain.pem"
cert = (cert_file_path, key_file_path,ca_cert)
header={"accept":"application/json","Content-Type":"application/json"}

#url="https://192.168.51.248/ejbca/ejbca-rest-api/v1/endentity/QWERTYUI"
#url= "https://192.168.51.248/ejbca/ejbca-rest-api/v1/ca/CN=HughesRootCA/certificate/download"
#url = https://192.168.51.248/ejbca/ejbca-rest-api/v1/certificate/pkcs10enrol
#site='{"username":"AASIT131D2_march23_test2","password":"somerandomdeneratedstring1","subject_dn":"CN=AASIT131D2_march23_test2,O=HNS","ca_name":"CAIdentifier","certificate_profile_name":"SCEP-TLS-Server-Client-Auth-IpSec","end_entity_profile_name":"SCEP-Device","token":"USERGENERATED"}'
#site='{"username": "AASIT019D", "password": "1247wEBBI$", "subject_dn": "CN=AASIT135D2_march23_test2,O=HNS", "ca_name": "CAIdentifier", "certificate_profile_name": "SCEP-TLS-Server-Client-Auth-IpSec", "end_entity_profile_name": "SCEP-Device", "token": "USERGENERATED"}'
#site='{"certificate_request": "-----BEGIN CERTIFICATE REQUEST-----\nMIIDDzCCAfcCAQAwgYcxCzAJBgNVBAYTAlVTMQswCQYDVQQIEwJNRDETMBEGA1UE\nBxMKR2VybWFudG93bjEMMAoGA1UEChMDSE5TMQwwCgYDVQQLEwNITlMxGDAWBgNV\nBAMTD0FBU0lUMTMxRC1TTi1JUDEgMB4GCSqGSIb3DQEJARYRc2FuamF5QGh1Z2hl\ncy5jb20wggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDATRERsPkjhK+V\nwfw6ZZpzY2Xj6/W3pyXeulgWX9LWxHKMuK9TlknGU5cnW3CDu8GPoc3zHJta3S7n\nU07DN5sWadRYhb63PAObEQzYetZWgdZtcbeTBBzt+ZsHtg51t61fd9bo/0/9UPaG\nuTIEmLFeTQKNXqzozGmnYFUKt9JO2jg7iLvAtUi2Gk9mxmfvU3amfbPaY8s+rR4g\nYKIjmfRgPwfuEHdRDPPwF9wFfnkHk+QPu5EdaAVlqQCRpFAjNxfADrYMqEoPEt2g\ngpke1sA2vczWSm0qJpQrcFkXMR88gH6IuocCJKFW/cHx2Y4H2wBu7XX0BJ+XLbJM\nau6oJHStAgMBAAGgQjAXBgkqhkiG9w0BCQcxChMIQXhsMDdqd2MwJwYJKoZIhvcN\nAQkOMRowGDAJBgNVHRMEAjAAMAsGA1UdDwQEAwIFoDANBgkqhkiG9w0BAQsFAAOC\nAQEAmVq/lDDrg8lzbl2JsrbLF0EX0mj1+JOhoaKccYn0a8FqrNDCvU2CWriHSz10\nOkZhslSiV+70keIdXeB2/Ny10BAzBid0V+SBXLo4uytVvGPPq8slf1Zs9PUHFd8C\nGws7HzNzA1zxqKkjE3Ki/7KLmSGGeEiqH1ACQXfmIKnTU8AQpfZMcChzhXoDBRKl\nTcMLS7B8CG15SwRh+LcEe0Jaj2iIwYClOYcq0RrH8zxGsFvbE6c/W0aTZVBVJarf\ne7/Jop11jcd7avJFDyw6jHUNl8AbyqFVtB90W2/6lohiyxtV6BJqgaFd59/z1Haq\nYQzJYJalMTfgv4VB+wWZ+tE7nQ==\n-----END CERTIFICATE REQUEST-----","certificate_profile_name": "SCEP-TLS-Server-Client-Auth-IpSec","end_entity_profile_name": "SCEP-Device","certificate_authority_name": "CAIdentifier","username": "AASIT131D-SN-IP","password": "Axl07jwc"}'

getcaname = "https://192.168.51.248/ejbca/ejbca-rest-api/v1/ca"
getcacert = "https://192.168.51.248/ejbca/ejbca-rest-api/v1/ca/{subject_dn}/certificate/download"
res=requests.get(url=getcaname,cert=cert,headers=header,verify=False)
print(res.text)
print(res.status_code)