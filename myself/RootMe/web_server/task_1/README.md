## HTML - Source code

### Task

Find password for administration section.

### Solution

Get web page using `curl` and read password in code commnets:

```html
$ curl http://challenge01.root-me.org/web-serveur/ch1/
<html><body><link rel='stylesheet' property='stylesheet' id='s' type='text/css' href='/template/s.css' media='all' /><iframe id='iframe' src='https://www.root-me.org/?page=externe_header'></iframe>

<!--

Bienvenue sur ce portail,
Welcome on this portal,

J'espère que vous passerez un agréable moment parmi nous, mais surtout que vous repartirez plein de choses dans la tête...
I hope that you will enjoy your time among us, and above that all you will leave with lots of things in the head ...

@ très bientôt
See ya

-->
<h1>Login v0.00001</h1>

<form>
    Password&nbsp;<input type="password" value="" name="password"/><br/>
    <input type="submit" value="login" />
</form>

<!--
                                                                                                                                                                                                                                                        Je crois que c'est vraiment trop simple là !
                                                                                                                                                                                                                                                            It's really too easy !
                                                                                                                                                                                                                                                                 password : nZ^&@q5&sjJHev0

-->

</body></html>
```

### Answer

Password is `nZ^&@q5&sjJHev0`
