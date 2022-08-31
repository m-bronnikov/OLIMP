## PE x86 - 0 protection

### Task

Extract password from provided executable in PE (Windows Portable Executable) format.


### Solution

#### First idea

Dump all string literals from exe and apply brute force using [bash script](brute_force.sh), but this solution was not successfull

#### Second idea

1. Dump segment of exe with string literals using:

```bash
objdump -s -j .rdata ch15.exe | more > rdata
```

From result file we see address of wrong message `Wrong password` and good message `Gratz man :)`.

2. Dump other segments with code using:

```bash
objdump -M intel -d ch15.exe > dump
```

We are interested in following part of assempbler code:

```asm
  401733:	83 7d 0c 07          	cmp    DWORD PTR [ebp+0xc],0x7
  401737:	75 71                	jne    0x4017aa
  401739:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  40173c:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  40173f:	3c 53                	cmp    al,0x53
  401741:	75 67                	jne    0x4017aa
  401743:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  401746:	83 c0 01             	add    eax,0x1
  401749:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  40174c:	3c 50                	cmp    al,0x50
  40174e:	75 5a                	jne    0x4017aa
  401750:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  401753:	83 c0 02             	add    eax,0x2
  401756:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  401759:	3c 61                	cmp    al,0x61
  40175b:	75 4d                	jne    0x4017aa
  40175d:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  401760:	83 c0 03             	add    eax,0x3
  401763:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  401766:	3c 43                	cmp    al,0x43
  401768:	75 40                	jne    0x4017aa
  40176a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  40176d:	83 c0 04             	add    eax,0x4
  401770:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  401773:	3c 49                	cmp    al,0x49
  401775:	75 33                	jne    0x4017aa
  401777:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  40177a:	83 c0 05             	add    eax,0x5
  40177d:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  401780:	3c 6f                	cmp    al,0x6f
  401782:	75 26                	jne    0x4017aa
  401784:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  401787:	83 c0 06             	add    eax,0x6
  40178a:	0f b6 00             	movzx  eax,BYTE PTR [eax]
  40178d:	3c 53                	cmp    al,0x53
  40178f:	75 19                	jne    0x4017aa
  401791:	b8 53 40 40 00       	mov    eax,0x404053
  401796:	89 04 24             	mov    DWORD PTR [esp],eax
  401799:	e8 12 11 00 00       	call   0x4028b0
  40179e:	c7 04 24 00 00 00 00 	mov    DWORD PTR [esp],0x0
  4017a5:	e8 f6 10 00 00       	call   0x4028a0
  4017aa:	c7 04 24 60 40 40 00 	mov    DWORD PTR [esp],0x404060
  4017b1:	e8 02 11 00 00       	call   0x4028b8
  4017b6:	c9                   	leave
```

We can see comparison of length with value `7` and than 7 comparisons with values: `0x53, 0x50, 0x61, 0x43, 0x49, 0x6f, 0x53`. Each wrong comparison leads to block which prints wrong mesaage, but at the end of all of them print of good message (`0x404053`) exist with `leave`.

Using python we can easily evaluate result:

```python
>>> ans = [0x53, 0x50, 0x61, 0x43, 0x49, 0x6f, 0x53]
>>> str().join(map(chr, ans))
'SPaCIoS'
```

### Answer 

Password is `SPaCIoS`.