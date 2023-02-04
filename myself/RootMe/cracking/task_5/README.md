## Cracking godot engine game

### Extracting resources

The reason why game is provided without `.pck` file is probably because `.pck` file is embedded into [executable file](0_protection.exe). After taking a look at executable's segments, it possible to find segment with name `<pck>`.

Dump of segment using `objdump` gives too small information (only some magic string):

```asm
0_protection.exe:     формат файла pei-x86-64

Содержимое раздела pck:
 2138000 47445043 01000000                    GDPC....  

```

After investigation of [commit](https://github.com/godotengine/godot/commit/40f4d3cf0fea814e23de33db1f1f02ebe05292ab) which adds this feature (resources embedding), it becomes clear that small segment size is feature of `<pck>` embedding and was made to not allocate address space for these resources data. Resources itself are written to the end of executable after last `PE` segment.

End of last segment can be found by dump of all segments using `objdump -D  0_protection.exe > dump` and simple scrolling down to the end of file. Last segment is `<.reloc>:` with last line at address (inside file) `0x23d498f`:

```asm
 23d498f:	a0                   	.byte 0xa0
```

So, resources can be extracted by trunkating of executable file from address `0x23d498f` to the end of file. Following [python code](read.py) makes extraction:

```python
with open('0_protection.exe', 'rb') as fb:
    fb.seek(0x23d498f)
    data = fb.read()

    with open('pck', 'wb') as fw:
        fw.write(data)

print("write is done")
```

Looking to extracted data in hex reader with search by keyword `island` gives 5 occurences. In location of these occurences placed human-readable code (script) which starts from byte `0x00645A70` and ends in byte `0x00651D60` of exracted data. This script can be extracted using following [python code](extract.py) into [script](script) file:

```python
with open('pck', 'rb') as fb:
    fb.seek(0x00645A70)
    data = fb.read(0x00651D60 - 0x00645A70)

    with open('script', 'wb') as fw:
        fw.write(data)

print("write is done")
```

### Resources investigation

File [script](script) obatained with steps bellow can be opened with common text editor. After simple reading of this file, following lines of code can be found:

```python
[node name="island" parent="." instance=ExtResource( 4 )]
transform = Transform( 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 100, 0 )

[node name="DirectionalLight" type="DirectionalLight" parent="."]
transform = Transform( 0.0130982, 0.88786, 0.459928, 0.175712, -0.454853, 0.87306, 0.984354, 0.0693795, -0.161966, 23.5124, 116.367, -2.55636 )

[node name="Skull" parent="." instance=ExtResource( 6 )]
transform = Transform( -0.879921, 0.170502, -0.443473, 0.277082, 0.942382, -0.187458, 0.385959, -0.287827, -0.876465, -20.4412, 1.0622, 24.0484 )

[node name="Skull2" parent="." instance=ExtResource( 6 )]
transform = Transform( -0.795691, 0.376893, -0.474159, -0.33972, -0.925798, -0.165797, -0.501463, 0.0291584, 0.864688, -14.4989, 1.17162, 23.5443 )

[node name="Skull3" parent="." instance=ExtResource( 6 )]
transform = Transform( -0.463258, 0.077463, 0.882832, 0.187189, 0.98225, 0.0120395, -0.866229, 0.170834, -0.469535, -20.5608, 1.28004, -23.5804 )

[node name="Skull4" parent="." instance=ExtResource( 6 )]
transform = Transform( -0.377068, 0.139509, -0.915618, -0.359136, -0.933268, 0.00570058, -0.853722, 0.330981, 0.402008, -8.82061, 1.25139, -25.1129 )

[node name="Skull5" parent="." instance=ExtResource( 6 )]
transform = Transform( -0.100903, 0.994721, 0.0186828, 0.0539442, 0.0242212, -0.99825, -0.993433, -0.0997186, -0.0561035, -2.84876, 0.862436, -25.3227 )
```


This is definition of locations for game objects from scene. For `island` game object (which contains password data, according to information from task) all coordinats are near 0, but one coord is 100, so assume this is a coord of island location's heigth in scene's coordinate system. If assumption is true, changing of this value to 0 (or 1) can locate island to heigth which can be accessed by player.


### Patching

To patch [executable file](0_protection.exe) with another coordinate value of island, hex editor can be used. To patch it just open exe in editor and seek down to byte number `0x23d498f + 0x645A70 = 0x2a1a3ff` and search for following text:

```
ePath("../../Wall2")
material/0 = SubResource( 12 )

[node name="island" parent="." instance=ExtResource( 4 )]
transform = Transform( 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 100, 0 )

[node name="Direct
```

After text is found just change value 100 to value 000 using hex editor and save file.


### Answer

After launch of game player can see island on same heigth level as a ground. On island placed table with password.

The password is: `ScriPts1nCl34r`

----------------------

**Made by Bronnikov Maksim**
