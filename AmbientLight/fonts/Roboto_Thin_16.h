// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version!
const uint8_t Roboto_Thin_16[] PROGMEM = {
	0x0F, // Width: 15
	0x13, // Height: 19
	0x20, // First Char: 32
	0xE0, // Numbers of Chars: 224

	// Jump Table:
	0xFF, 0xFF, 0x00, 0x04,  // 32:65535
	0x00, 0x00, 0x05, 0x03,  // 33:0
	0x00, 0x05, 0x07, 0x04,  // 34:5
	0x00, 0x0C, 0x1A, 0x09,  // 35:12
	0x00, 0x26, 0x17, 0x09,  // 36:38
	0x00, 0x3D, 0x20, 0x0C,  // 37:61
	0x00, 0x5D, 0x1A, 0x0A,  // 38:93
	0x00, 0x77, 0x04, 0x03,  // 39:119
	0x00, 0x7B, 0x0F, 0x05,  // 40:123
	0x00, 0x8A, 0x0B, 0x05,  // 41:138
	0x00, 0x95, 0x13, 0x07,  // 42:149
	0x00, 0xA8, 0x17, 0x09,  // 43:168
	0x00, 0xBF, 0x06, 0x03,  // 44:191
	0x00, 0xC5, 0x0B, 0x05,  // 45:197
	0x00, 0xD0, 0x05, 0x03,  // 46:208
	0x00, 0xD5, 0x0D, 0x06,  // 47:213
	0x00, 0xE2, 0x17, 0x09,  // 48:226
	0x00, 0xF9, 0x0E, 0x09,  // 49:249
	0x01, 0x07, 0x17, 0x09,  // 50:263
	0x01, 0x1E, 0x17, 0x09,  // 51:286
	0x01, 0x35, 0x1A, 0x09,  // 52:309
	0x01, 0x4F, 0x17, 0x09,  // 53:335
	0x01, 0x66, 0x17, 0x09,  // 54:358
	0x01, 0x7D, 0x16, 0x09,  // 55:381
	0x01, 0x93, 0x17, 0x09,  // 56:403
	0x01, 0xAA, 0x17, 0x09,  // 57:426
	0x01, 0xC1, 0x05, 0x03,  // 58:449
	0x01, 0xC6, 0x06, 0x03,  // 59:454
	0x01, 0xCC, 0x14, 0x08,  // 60:460
	0x01, 0xE0, 0x17, 0x09,  // 61:480
	0x01, 0xF7, 0x14, 0x08,  // 62:503
	0x02, 0x0B, 0x10, 0x07,  // 63:523
	0x02, 0x1B, 0x29, 0x0F,  // 64:539
	0x02, 0x44, 0x1D, 0x0A,  // 65:580
	0x02, 0x61, 0x1A, 0x0A,  // 66:609
	0x02, 0x7B, 0x1A, 0x0A,  // 67:635
	0x02, 0x95, 0x1A, 0x0A,  // 68:661
	0x02, 0xAF, 0x17, 0x09,  // 69:687
	0x02, 0xC6, 0x19, 0x09,  // 70:710
	0x02, 0xDF, 0x1D, 0x0B,  // 71:735
	0x02, 0xFC, 0x1A, 0x0B,  // 72:764
	0x03, 0x16, 0x05, 0x04,  // 73:790
	0x03, 0x1B, 0x14, 0x09,  // 74:795
	0x03, 0x2F, 0x1D, 0x0A,  // 75:815
	0x03, 0x4C, 0x17, 0x08,  // 76:844
	0x03, 0x63, 0x23, 0x0E,  // 77:867
	0x03, 0x86, 0x1D, 0x0B,  // 78:902
	0x03, 0xA3, 0x1D, 0x0B,  // 79:931
	0x03, 0xC0, 0x1A, 0x0A,  // 80:960
	0x03, 0xDA, 0x1D, 0x0B,  // 81:986
	0x03, 0xF7, 0x1A, 0x0A,  // 82:1015
	0x04, 0x11, 0x1A, 0x09,  // 83:1041
	0x04, 0x2B, 0x19, 0x0A,  // 84:1067
	0x04, 0x44, 0x1A, 0x0B,  // 85:1092
	0x04, 0x5E, 0x1C, 0x0A,  // 86:1118
	0x04, 0x7A, 0x28, 0x0F,  // 87:1146
	0x04, 0xA2, 0x1A, 0x0A,  // 88:1186
	0x04, 0xBC, 0x19, 0x0A,  // 89:1212
	0x04, 0xD5, 0x1A, 0x0A,  // 90:1237
	0x04, 0xEF, 0x09, 0x03,  // 91:1263
	0x04, 0xF8, 0x11, 0x06,  // 92:1272
	0x05, 0x09, 0x06, 0x03,  // 93:1289
	0x05, 0x0F, 0x11, 0x07,  // 94:1295
	0x05, 0x20, 0x14, 0x07,  // 95:1312
	0x05, 0x34, 0x07, 0x04,  // 96:1332
	0x05, 0x3B, 0x14, 0x08,  // 97:1339
	0x05, 0x4F, 0x17, 0x09,  // 98:1359
	0x05, 0x66, 0x14, 0x08,  // 99:1382
	0x05, 0x7A, 0x17, 0x09,  // 100:1402
	0x05, 0x91, 0x14, 0x08,  // 101:1425
	0x05, 0xA5, 0x0D, 0x05,  // 102:1445
	0x05, 0xB2, 0x17, 0x09,  // 103:1458
	0x05, 0xC9, 0x17, 0x09,  // 104:1481
	0x05, 0xE0, 0x05, 0x03,  // 105:1504
	0x05, 0xE5, 0x06, 0x03,  // 106:1509
	0x05, 0xEB, 0x17, 0x08,  // 107:1515
	0x06, 0x02, 0x05, 0x03,  // 108:1538
	0x06, 0x07, 0x26, 0x0E,  // 109:1543
	0x06, 0x2D, 0x17, 0x09,  // 110:1581
	0x06, 0x44, 0x17, 0x09,  // 111:1604
	0x06, 0x5B, 0x17, 0x09,  // 112:1627
	0x06, 0x72, 0x18, 0x09,  // 113:1650
	0x06, 0x8A, 0x0D, 0x05,  // 114:1674
	0x06, 0x97, 0x14, 0x08,  // 115:1687
	0x06, 0xAB, 0x0B, 0x05,  // 116:1707
	0x06, 0xB6, 0x17, 0x09,  // 117:1718
	0x06, 0xCD, 0x16, 0x08,  // 118:1741
	0x06, 0xE3, 0x20, 0x0C,  // 119:1763
	0x07, 0x03, 0x14, 0x08,  // 120:1795
	0x07, 0x17, 0x16, 0x08,  // 121:1815
	0x07, 0x2D, 0x17, 0x08,  // 122:1837
	0x07, 0x44, 0x0F, 0x05,  // 123:1860
	0x07, 0x53, 0x06, 0x03,  // 124:1875
	0x07, 0x59, 0x0E, 0x05,  // 125:1881
	0x07, 0x67, 0x1D, 0x0B,  // 126:1895
	0x07, 0x84, 0x11, 0x07,  // 127:1924
	0x07, 0x95, 0x11, 0x07,  // 128:1941
	0x07, 0xA6, 0x11, 0x07,  // 129:1958
	0x07, 0xB7, 0x11, 0x07,  // 130:1975
	0x07, 0xC8, 0x11, 0x07,  // 131:1992
	0x07, 0xD9, 0x11, 0x07,  // 132:2009
	0x07, 0xEA, 0x11, 0x07,  // 133:2026
	0x07, 0xFB, 0x11, 0x07,  // 134:2043
	0x08, 0x0C, 0x11, 0x07,  // 135:2060
	0x08, 0x1D, 0x11, 0x07,  // 136:2077
	0x08, 0x2E, 0x11, 0x07,  // 137:2094
	0x08, 0x3F, 0x11, 0x07,  // 138:2111
	0x08, 0x50, 0x11, 0x07,  // 139:2128
	0x08, 0x61, 0x11, 0x07,  // 140:2145
	0x08, 0x72, 0x11, 0x07,  // 141:2162
	0x08, 0x83, 0x11, 0x07,  // 142:2179
	0x08, 0x94, 0x11, 0x07,  // 143:2196
	0x08, 0xA5, 0x11, 0x07,  // 144:2213
	0x08, 0xB6, 0x11, 0x07,  // 145:2230
	0x08, 0xC7, 0x11, 0x07,  // 146:2247
	0x08, 0xD8, 0x11, 0x07,  // 147:2264
	0x08, 0xE9, 0x11, 0x07,  // 148:2281
	0x08, 0xFA, 0x11, 0x07,  // 149:2298
	0x09, 0x0B, 0x11, 0x07,  // 150:2315
	0x09, 0x1C, 0x11, 0x07,  // 151:2332
	0x09, 0x2D, 0x11, 0x07,  // 152:2349
	0x09, 0x3E, 0x11, 0x07,  // 153:2366
	0x09, 0x4F, 0x11, 0x07,  // 154:2383
	0x09, 0x60, 0x11, 0x07,  // 155:2400
	0x09, 0x71, 0x11, 0x07,  // 156:2417
	0x09, 0x82, 0x11, 0x07,  // 157:2434
	0x09, 0x93, 0x11, 0x07,  // 158:2451
	0x09, 0xA4, 0x11, 0x07,  // 159:2468
	0xFF, 0xFF, 0x00, 0x04,  // 160:65535
	0x09, 0xB5, 0x06, 0x03,  // 161:2485
	0x09, 0xBB, 0x17, 0x09,  // 162:2491
	0x09, 0xD2, 0x17, 0x09,  // 163:2514
	0x09, 0xE9, 0x20, 0x0C,  // 164:2537
	0x0A, 0x09, 0x16, 0x08,  // 165:2569
	0x0A, 0x1F, 0x06, 0x03,  // 166:2591
	0x0A, 0x25, 0x1A, 0x0A,  // 167:2597
	0x0A, 0x3F, 0x10, 0x07,  // 168:2623
	0x0A, 0x4F, 0x23, 0x0D,  // 169:2639
	0x0A, 0x72, 0x11, 0x07,  // 170:2674
	0x0A, 0x83, 0x14, 0x07,  // 171:2691
	0x0A, 0x97, 0x14, 0x09,  // 172:2711
	0x0A, 0xAB, 0x0B, 0x05,  // 173:2731
	0x0A, 0xB6, 0x23, 0x0D,  // 174:2742
	0x0A, 0xD9, 0x0D, 0x06,  // 175:2777
	0x0A, 0xE6, 0x0D, 0x06,  // 176:2790
	0x0A, 0xF3, 0x17, 0x08,  // 177:2803
	0x0B, 0x0A, 0x0E, 0x06,  // 178:2826
	0x0B, 0x18, 0x0E, 0x06,  // 179:2840
	0x0B, 0x26, 0x07, 0x04,  // 180:2854
	0x0B, 0x2D, 0x17, 0x09,  // 181:2861
	0x0B, 0x44, 0x11, 0x07,  // 182:2884
	0x0B, 0x55, 0x05, 0x04,  // 183:2901
	0x0B, 0x5A, 0x09, 0x04,  // 184:2906
	0x0B, 0x63, 0x0B, 0x06,  // 185:2915
	0x0B, 0x6E, 0x10, 0x07,  // 186:2926
	0x0B, 0x7E, 0x11, 0x07,  // 187:2942
	0x0B, 0x8F, 0x20, 0x0B,  // 188:2959
	0x0B, 0xAF, 0x20, 0x0C,  // 189:2991
	0x0B, 0xCF, 0x23, 0x0C,  // 190:3023
	0x0B, 0xF2, 0x12, 0x07,  // 191:3058
	0x0C, 0x04, 0x1D, 0x0A,  // 192:3076
	0x0C, 0x21, 0x1D, 0x0A,  // 193:3105
	0x0C, 0x3E, 0x1D, 0x0A,  // 194:3134
	0x0C, 0x5B, 0x1D, 0x0A,  // 195:3163
	0x0C, 0x78, 0x1D, 0x0A,  // 196:3192
	0x0C, 0x95, 0x1D, 0x0A,  // 197:3221
	0x0C, 0xB2, 0x29, 0x0E,  // 198:3250
	0x0C, 0xDB, 0x1A, 0x0A,  // 199:3291
	0x0C, 0xF5, 0x17, 0x09,  // 200:3317
	0x0D, 0x0C, 0x17, 0x09,  // 201:3340
	0x0D, 0x23, 0x17, 0x09,  // 202:3363
	0x0D, 0x3A, 0x17, 0x09,  // 203:3386
	0x0D, 0x51, 0x05, 0x04,  // 204:3409
	0x0D, 0x56, 0x0A, 0x04,  // 205:3414
	0x0D, 0x60, 0x0A, 0x04,  // 206:3424
	0x0D, 0x6A, 0x05, 0x04,  // 207:3434
	0x0D, 0x6F, 0x1D, 0x0B,  // 208:3439
	0x0D, 0x8C, 0x1D, 0x0B,  // 209:3468
	0x0D, 0xA9, 0x1D, 0x0B,  // 210:3497
	0x0D, 0xC6, 0x1D, 0x0B,  // 211:3526
	0x0D, 0xE3, 0x1D, 0x0B,  // 212:3555
	0x0E, 0x00, 0x1D, 0x0B,  // 213:3584
	0x0E, 0x1D, 0x1D, 0x0B,  // 214:3613
	0x0E, 0x3A, 0x14, 0x08,  // 215:3642
	0x0E, 0x4E, 0x1D, 0x0B,  // 216:3662
	0x0E, 0x6B, 0x1A, 0x0B,  // 217:3691
	0x0E, 0x85, 0x1A, 0x0B,  // 218:3717
	0x0E, 0x9F, 0x1A, 0x0B,  // 219:3743
	0x0E, 0xB9, 0x1A, 0x0B,  // 220:3769
	0x0E, 0xD3, 0x19, 0x0A,  // 221:3795
	0x0E, 0xEC, 0x1A, 0x0A,  // 222:3820
	0x0F, 0x06, 0x17, 0x09,  // 223:3846
	0x0F, 0x1D, 0x14, 0x08,  // 224:3869
	0x0F, 0x31, 0x14, 0x08,  // 225:3889
	0x0F, 0x45, 0x14, 0x08,  // 226:3909
	0x0F, 0x59, 0x14, 0x08,  // 227:3929
	0x0F, 0x6D, 0x14, 0x08,  // 228:3949
	0x0F, 0x81, 0x14, 0x08,  // 229:3969
	0x0F, 0x95, 0x26, 0x0E,  // 230:3989
	0x0F, 0xBB, 0x14, 0x08,  // 231:4027
	0x0F, 0xCF, 0x14, 0x08,  // 232:4047
	0x0F, 0xE3, 0x14, 0x08,  // 233:4067
	0x0F, 0xF7, 0x14, 0x08,  // 234:4087
	0x10, 0x0B, 0x14, 0x08,  // 235:4107
	0x10, 0x1F, 0x05, 0x03,  // 236:4127
	0x10, 0x24, 0x07, 0x03,  // 237:4132
	0x10, 0x2B, 0x07, 0x03,  // 238:4139
	0x10, 0x32, 0x05, 0x03,  // 239:4146
	0x10, 0x37, 0x17, 0x09,  // 240:4151
	0x10, 0x4E, 0x17, 0x09,  // 241:4174
	0x10, 0x65, 0x17, 0x09,  // 242:4197
	0x10, 0x7C, 0x17, 0x09,  // 243:4220
	0x10, 0x93, 0x17, 0x09,  // 244:4243
	0x10, 0xAA, 0x17, 0x09,  // 245:4266
	0x10, 0xC1, 0x17, 0x09,  // 246:4289
	0x10, 0xD8, 0x17, 0x09,  // 247:4312
	0x10, 0xEF, 0x17, 0x09,  // 248:4335
	0x11, 0x06, 0x17, 0x09,  // 249:4358
	0x11, 0x1D, 0x17, 0x09,  // 250:4381
	0x11, 0x34, 0x17, 0x09,  // 251:4404
	0x11, 0x4B, 0x17, 0x09,  // 252:4427
	0x11, 0x62, 0x16, 0x08,  // 253:4450
	0x11, 0x78, 0x17, 0x09,  // 254:4472
	0x11, 0x8F, 0x16, 0x08,  // 255:4495

	// Font Data:
	0x00,0x00,0x00,0xF8,0x4F,	// 33
	0x00,0x00,0x00,0x38,0x00,0x00,0x38,	// 34
	0x00,0x00,0x00,0x40,0x08,0x00,0x40,0x7E,0x00,0xF8,0x09,0x00,0x48,0x08,0x00,0x40,0x78,0x00,0xE0,0x0F,0x00,0x58,0x08,0x00,0x40,0x08,	// 35
	0x00,0x00,0x00,0x60,0x10,0x00,0x90,0x20,0x00,0x08,0x41,0x00,0x0C,0xC1,0x01,0x08,0x42,0x00,0x18,0x42,0x00,0x20,0x3C,	// 36
	0x00,0x00,0x00,0x70,0x00,0x00,0x88,0x00,0x00,0x88,0x30,0x00,0x70,0x08,0x00,0x00,0x06,0x00,0x80,0x11,0x00,0x40,0x28,0x00,0x20,0x44,0x00,0x00,0x44,0x00,0x00,0x38,	// 37
	0x00,0x00,0x00,0x00,0x3C,0x00,0xF0,0x42,0x00,0x08,0x41,0x00,0x88,0x42,0x00,0x48,0x44,0x00,0x30,0x58,0x00,0x00,0x30,0x00,0x00,0x4C,	// 38
	0x00,0x00,0x00,0x38,	// 39
	0x00,0x00,0x00,0xC0,0x7F,0x00,0x30,0x80,0x01,0x0C,0x00,0x06,0x04,0x00,0x04,	// 40
	0x04,0x00,0x04,0x18,0x00,0x03,0xE0,0xE0,0x00,0x00,0x1F,	// 41
	0x20,0x00,0x00,0x20,0x01,0x00,0xC0,0x00,0x00,0x78,0x00,0x00,0xC0,0x01,0x00,0x20,0x01,0x00,0x20,	// 42
	0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0xC0,0x7F,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00,0x04,	// 43
	0x00,0x00,0x00,0x00,0xC0,0x01,	// 44
	0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00,0x04,	// 45
	0x00,0x00,0x00,0x00,0x40,	// 46
	0x00,0xC0,0x00,0x00,0x38,0x00,0x00,0x07,0x00,0xC0,0x00,0x00,0x38,	// 47
	0x00,0x00,0x00,0xE0,0x1F,0x00,0x10,0x20,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x10,0x20,0x00,0xE0,0x1F,	// 48
	0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x08,0x00,0x00,0xF8,0x7F,	// 49
	0x00,0x00,0x00,0x60,0x60,0x00,0x10,0x50,0x00,0x08,0x48,0x00,0x08,0x44,0x00,0x08,0x42,0x00,0xF0,0x41,0x00,0x40,0x40,	// 50
	0x00,0x00,0x00,0x20,0x18,0x00,0x10,0x20,0x00,0x08,0x41,0x00,0x08,0x41,0x00,0x08,0x41,0x00,0x90,0x42,0x00,0x60,0x3C,	// 51
	0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x09,0x00,0xC0,0x08,0x00,0x20,0x08,0x00,0x10,0x08,0x00,0xF8,0x7F,0x00,0x00,0x08,0x00,0x00,0x08,	// 52
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x39,0x00,0x88,0x40,0x00,0x88,0x40,0x00,0x88,0x40,0x00,0x88,0x40,0x00,0x08,0x3F,	// 53
	0x00,0x00,0x00,0xC0,0x1F,0x00,0x20,0x21,0x00,0x90,0x40,0x00,0x88,0x40,0x00,0x88,0x40,0x00,0x88,0x21,0x00,0x00,0x1E,	// 54
	0x00,0x00,0x00,0x08,0x00,0x00,0x08,0x40,0x00,0x08,0x38,0x00,0x08,0x06,0x00,0x88,0x01,0x00,0x68,0x00,0x00,0x18,	// 55
	0x00,0x00,0x00,0x60,0x3E,0x00,0x90,0x42,0x00,0x08,0x41,0x00,0x08,0x41,0x00,0x08,0x41,0x00,0x90,0x42,0x00,0x60,0x3C,	// 56
	0x00,0x00,0x00,0xE0,0x01,0x00,0x10,0x42,0x00,0x08,0x44,0x00,0x08,0x44,0x00,0x08,0x24,0x00,0x10,0x32,0x00,0xE0,0x0F,	// 57
	0x00,0x00,0x00,0x40,0x40,	// 58
	0x00,0x00,0x00,0x40,0xC0,0x01,	// 59
	0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x0A,0x00,0x00,0x0A,0x00,0x00,0x11,0x00,0x00,0x11,0x00,0x80,0x20,	// 60
	0x00,0x00,0x00,0x00,0x09,0x00,0x00,0x09,0x00,0x00,0x09,0x00,0x00,0x09,0x00,0x00,0x09,0x00,0x00,0x09,0x00,0x00,0x09,	// 61
	0x00,0x00,0x00,0x80,0x20,0x00,0x00,0x11,0x00,0x00,0x11,0x00,0x00,0x0A,0x00,0x00,0x0A,0x00,0x00,0x04,	// 62
	0x00,0x00,0x00,0x30,0x00,0x00,0x08,0x00,0x00,0x08,0x4C,0x00,0x08,0x03,0x00,0xF0,	// 63
	0x00,0x00,0x00,0x00,0xFF,0x00,0x80,0x00,0x01,0x40,0x00,0x02,0x20,0x3C,0x02,0x10,0x43,0x04,0x90,0x40,0x04,0x90,0x40,0x04,0x90,0x20,0x04,0x90,0x3F,0x02,0x10,0x40,0x00,0x20,0x40,0x00,0xC0,0x20,0x00,0x00,0x1F,	// 64
	0x00,0x40,0x00,0x00,0x30,0x00,0x00,0x0F,0x00,0xE0,0x08,0x00,0x18,0x08,0x00,0x70,0x08,0x00,0x80,0x09,0x00,0x00,0x0E,0x00,0x00,0x70,0x00,0x00,0x40,	// 65
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0xF0,0x45,0x00,0x00,0x38,	// 66
	0x00,0x00,0x00,0xE0,0x1F,0x00,0x10,0x20,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x10,0x20,0x00,0x60,0x18,	// 67
	0x00,0x00,0x00,0xF8,0x7F,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x10,0x20,0x00,0xE0,0x1F,	// 68
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x42,	// 69
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,	// 70
	0x00,0x00,0x00,0xC0,0x0F,0x00,0x30,0x30,0x00,0x10,0x20,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x44,0x00,0x08,0x44,0x00,0x30,0x44,0x00,0x40,0x3C,	// 71
	0x00,0x00,0x00,0xF8,0x7F,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0xF8,0x7F,	// 72
	0x00,0x00,0x00,0xF8,0x7F,	// 73
	0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0xF8,0x3F,	// 74
	0x00,0x00,0x00,0xF8,0x7F,0x00,0x00,0x02,0x00,0x00,0x01,0x00,0x80,0x02,0x00,0x40,0x04,0x00,0x20,0x18,0x00,0x10,0x20,0x00,0x08,0x40,0x00,0x00,0x40,	// 75
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,	// 76
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0xC0,0x00,0x00,0x00,0x07,0x00,0x00,0x18,0x00,0x00,0x60,0x00,0x00,0x30,0x00,0x00,0x0E,0x00,0x80,0x01,0x00,0x60,0x00,0x00,0xF8,0x7F,	// 77
	0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x60,0x00,0x00,0x80,0x00,0x00,0x00,0x03,0x00,0x00,0x04,0x00,0x00,0x18,0x00,0x00,0x20,0x00,0xF8,0x7F,	// 78
	0x00,0x00,0x00,0xE0,0x1F,0x00,0x10,0x20,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x30,0x30,0x00,0xC0,0x0F,	// 79
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x10,0x01,0x00,0xE0,0x01,	// 80
	0x00,0x00,0x00,0xE0,0x1F,0x00,0x10,0x20,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0xC0,0x00,0x30,0x30,0x01,0xC0,0x0F,	// 81
	0x00,0x00,0x00,0xF8,0x7F,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x0D,0x00,0x90,0x30,0x00,0x60,0x40,	// 82
	0x00,0x00,0x00,0xF0,0x30,0x00,0x88,0x40,0x00,0x08,0x41,0x00,0x08,0x41,0x00,0x08,0x41,0x00,0x08,0x42,0x00,0x30,0x36,0x00,0x00,0x08,	// 83
	0x00,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0xF8,0x7F,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,	// 84
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x3F,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x60,0x00,0xF8,0x3F,	// 85
	0x00,0x00,0x00,0x78,0x00,0x00,0x80,0x03,0x00,0x00,0x1C,0x00,0x00,0x60,0x00,0x00,0x30,0x00,0x00,0x0E,0x00,0xC0,0x01,0x00,0x38,0x00,0x00,0x08,	// 86
	0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x0F,0x00,0x00,0x70,0x00,0x00,0x38,0x00,0x80,0x07,0x00,0x70,0x00,0x00,0x38,0x00,0x00,0xC0,0x01,0x00,0x00,0x1E,0x00,0x00,0x60,0x00,0x00,0x3C,0x00,0xC0,0x03,0x00,0x38,	// 87
	0x00,0x00,0x00,0x18,0x60,0x00,0x20,0x18,0x00,0xC0,0x04,0x00,0x00,0x03,0x00,0x80,0x07,0x00,0x40,0x08,0x00,0x30,0x30,0x00,0x08,0x40,	// 88
	0x08,0x00,0x00,0x30,0x00,0x00,0x40,0x00,0x00,0x80,0x01,0x00,0x00,0x7E,0x00,0x00,0x03,0x00,0xC0,0x00,0x00,0x20,0x00,0x00,0x18,	// 89
	0x00,0x00,0x00,0x08,0x60,0x00,0x08,0x58,0x00,0x08,0x44,0x00,0x08,0x42,0x00,0x88,0x41,0x00,0x48,0x40,0x00,0x38,0x40,0x00,0x08,0x40,	// 90
	0x00,0x00,0x00,0xFC,0xFF,0x01,0x04,0x00,0x01,	// 91
	0x18,0x00,0x00,0x60,0x00,0x00,0x80,0x03,0x00,0x00,0x1C,0x00,0x00,0xE0,0x00,0x00,0x80,	// 92
	0x04,0x00,0x01,0xFC,0xFF,0x01,	// 93
	0x00,0x00,0x00,0xC0,0x01,0x00,0x30,0x00,0x00,0x18,0x00,0x00,0xE0,0x00,0x00,0x00,0x01,	// 94
	0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,	// 95
	0x00,0x00,0x00,0x08,0x00,0x00,0x10,	// 96
	0x00,0x00,0x00,0x80,0x3C,0x00,0x40,0x42,0x00,0x40,0x42,0x00,0x40,0x42,0x00,0x40,0x22,0x00,0x80,0x7F,	// 97
	0x00,0x00,0x00,0xF8,0x7F,0x00,0x80,0x20,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x80,0x20,0x00,0x00,0x1F,	// 98
	0x00,0x00,0x00,0x80,0x3F,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x80,0x31,	// 99
	0x00,0x00,0x00,0x00,0x1F,0x00,0x80,0x20,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x80,0x20,0x00,0xF8,0x7F,	// 100
	0x00,0x00,0x00,0x80,0x3F,0x00,0xC0,0x44,0x00,0x40,0x44,0x00,0x40,0x44,0x00,0x40,0x44,0x00,0x80,0x27,	// 101
	0x00,0x00,0x00,0xE0,0x7F,0x00,0x50,0x00,0x00,0x48,0x00,0x00,0x48,	// 102
	0x00,0x00,0x00,0x00,0x1F,0x01,0x80,0x20,0x02,0x40,0x40,0x02,0x40,0x40,0x02,0x40,0x40,0x02,0x80,0xA0,0x01,0xC0,0x7F,	// 103
	0x00,0x00,0x00,0xF8,0x7F,0x00,0x80,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0xC0,0x00,0x00,0x00,0x7F,	// 104
	0x00,0x00,0x00,0xC8,0x7F,	// 105
	0x00,0x00,0x02,0xC8,0xFF,0x01,	// 106
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0x00,0x06,0x00,0x00,0x09,0x00,0x80,0x30,0x00,0x40,0x40,0x00,0x00,0x40,	// 107
	0x00,0x00,0x00,0xF8,0x7F,	// 108
	0x00,0x00,0x00,0xC0,0x7F,0x00,0x80,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x80,0x7E,0x00,0x80,0x01,0x00,0xC0,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x80,0x7F,	// 109
	0x00,0x00,0x00,0xC0,0x7F,0x00,0x80,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0xC0,0x00,0x00,0x00,0x7F,	// 110
	0x00,0x00,0x00,0x00,0x1F,0x00,0x80,0x20,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x80,0x20,0x00,0x00,0x1F,	// 111
	0x00,0x00,0x00,0xC0,0xFF,0x03,0x80,0x20,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x80,0x20,0x00,0x00,0x1F,	// 112
	0x00,0x00,0x00,0x00,0x1F,0x00,0x80,0x20,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x80,0x20,0x00,0xC0,0xFF,0x03,	// 113
	0x00,0x00,0x00,0xC0,0x7F,0x00,0x80,0x00,0x00,0x40,0x00,0x00,0x40,	// 114
	0x00,0x00,0x00,0x80,0x21,0x00,0x40,0x42,0x00,0x40,0x44,0x00,0x40,0x44,0x00,0x40,0x44,0x00,0x80,0x38,	// 115
	0x40,0x00,0x00,0xF0,0x3F,0x00,0x40,0x40,0x00,0x40,0x40,	// 116
	0x00,0x00,0x00,0xC0,0x1F,0x00,0x00,0x60,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x20,0x00,0xC0,0x7F,	// 117
	0x00,0x00,0x00,0xC0,0x03,0x00,0x00,0x1C,0x00,0x00,0x60,0x00,0x00,0x30,0x00,0x00,0x0E,0x00,0xC0,0x01,0x00,0x40,	// 118
	0x00,0x00,0x00,0xC0,0x07,0x00,0x00,0x38,0x00,0x00,0x70,0x00,0x00,0x0F,0x00,0xC0,0x00,0x00,0x80,0x07,0x00,0x00,0x38,0x00,0x00,0x60,0x00,0x00,0x1E,0x00,0xC0,0x01,	// 119
	0x00,0x00,0x00,0xC0,0x60,0x00,0x00,0x19,0x00,0x00,0x06,0x00,0x00,0x0A,0x00,0x80,0x31,0x00,0x40,0x40,	// 120
	0x00,0x00,0x00,0xC0,0x03,0x02,0x00,0x0C,0x02,0x00,0xF0,0x01,0x00,0x38,0x00,0x00,0x06,0x00,0xC0,0x01,0x00,0x40,	// 121
	0x00,0x00,0x00,0x40,0x60,0x00,0x40,0x58,0x00,0x40,0x44,0x00,0x40,0x42,0x00,0x40,0x41,0x00,0xC0,0x40,0x00,0x00,0x40,	// 122
	0x00,0x00,0x00,0x00,0x0C,0x00,0xF0,0xFB,0x01,0x10,0x00,0x02,0x08,0x00,0x02,	// 123
	0x00,0x00,0x00,0xF8,0xFF,0x01,	// 124
	0x08,0x00,0x02,0x30,0x00,0x01,0xC0,0xFB,0x00,0x00,0x0C,0x00,0x00,0x04,	// 125
	0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x02,0x00,0x00,0x02,0x00,0x00,0x02,0x00,0x00,0x04,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x06,	// 126
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 127
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 128
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 129
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 130
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 131
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 132
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 133
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 134
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 135
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 136
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 137
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 138
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 139
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 140
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 141
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 142
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 143
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 144
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 145
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 146
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 147
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 148
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 149
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 150
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 151
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 152
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 153
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 154
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 155
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 156
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 157
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 158
	0x00,0x00,0x00,0xF8,0x7F,0x00,0xC8,0x4C,0x00,0x88,0x47,0x00,0x68,0x58,0x00,0xF8,0x7F,	// 159
	0x00,0x00,0x00,0x40,0xFE,0x03,	// 161
	0x00,0x00,0x00,0x00,0x1F,0x00,0x80,0x20,0x00,0x40,0x40,0x00,0x60,0xC0,0x01,0x40,0x40,0x00,0x80,0x60,0x00,0x00,0x11,	// 162
	0x00,0x00,0x00,0x00,0x42,0x00,0xE0,0x7F,0x00,0x10,0x42,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x40,0x00,0x30,0x40,	// 163
	0x00,0x00,0x00,0x20,0x4F,0x00,0xC0,0x30,0x00,0x40,0x20,0x00,0x20,0x40,0x00,0x20,0x40,0x00,0x20,0x40,0x00,0x20,0x40,0x00,0x40,0x20,0x00,0xC0,0x39,0x00,0x20,0x46,	// 164
	0x18,0x00,0x00,0x60,0x14,0x00,0x80,0x14,0x00,0x00,0x7F,0x00,0x00,0x17,0x00,0xC0,0x14,0x00,0x30,0x14,0x00,0x08,	// 165
	0x00,0x00,0x00,0xF8,0xF9,0x01,	// 166
	0x00,0x00,0x00,0x60,0x8E,0x01,0x90,0x12,0x02,0x08,0x11,0x04,0x08,0x21,0x04,0x08,0x21,0x04,0x08,0x22,0x04,0x30,0xD2,0x03,0x40,0x0C,	// 167
	0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,	// 168
	0x00,0x00,0x00,0xC0,0x0F,0x00,0x20,0x10,0x00,0x10,0x23,0x00,0x88,0x44,0x00,0x48,0x48,0x00,0x48,0x48,0x00,0x48,0x48,0x00,0x88,0x44,0x00,0x10,0x20,0x00,0x20,0x10,0x00,0xC0,0x0F,	// 169
	0x00,0x00,0x00,0xD0,0x00,0x00,0x28,0x01,0x00,0x28,0x01,0x00,0x38,0x01,0x00,0xE0,0x01,	// 170
	0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x12,0x00,0x00,0x21,0x00,0x00,0x0C,0x00,0x00,0x12,0x00,0x00,0x21,	// 171
	0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x02,0x00,0x00,0x02,0x00,0x00,0x02,0x00,0x00,0x02,0x00,0x00,0x0E,	// 172
	0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00,0x04,	// 173
	0x00,0x00,0x00,0xC0,0x0F,0x00,0x20,0x10,0x00,0x10,0x20,0x00,0x88,0x4D,0x00,0x48,0x42,0x00,0x48,0x42,0x00,0x48,0x42,0x00,0x88,0x4D,0x00,0x10,0x20,0x00,0x60,0x18,0x00,0x80,0x07,	// 174
	0x00,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x10,	// 175
	0x00,0x00,0x00,0x30,0x00,0x00,0x48,0x00,0x00,0x48,0x00,0x00,0x30,	// 176
	0x00,0x02,0x00,0x00,0x42,0x00,0x00,0x42,0x00,0xE0,0x5F,0x00,0x00,0x42,0x00,0x00,0x42,0x00,0x00,0x42,0x00,0x00,0x02,	// 177
	0x00,0x00,0x00,0x10,0x03,0x00,0x88,0x02,0x00,0x48,0x02,0x00,0x30,0x02,	// 178
	0x00,0x00,0x00,0x10,0x01,0x00,0x48,0x02,0x00,0x48,0x02,0x00,0xB0,0x03,	// 179
	0x00,0x00,0x00,0x10,0x00,0x00,0x08,	// 180
	0x00,0x00,0x00,0xC0,0xFF,0x03,0x00,0x20,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x20,0x00,0xC0,0x7F,	// 181
	0x00,0x00,0x00,0xF0,0x03,0x00,0xF8,0x03,0x00,0xF8,0x07,0x00,0xF8,0x07,0x00,0xF8,0x7F,	// 182
	0x00,0x00,0x00,0x00,0x02,	// 183
	0x00,0x00,0x00,0x00,0x80,0x02,0x00,0x00,0x03,	// 184
	0x00,0x00,0x00,0x10,0x00,0x00,0x08,0x00,0x00,0xF8,0x03,	// 185
	0x00,0x00,0x00,0xF0,0x00,0x00,0x08,0x01,0x00,0x08,0x01,0x00,0x08,0x01,0x00,0xF0,	// 186
	0x00,0x00,0x00,0x00,0x21,0x00,0x00,0x16,0x00,0x00,0x29,0x00,0x00,0x16,0x00,0x00,0x08,	// 187
	0x00,0x00,0x00,0x10,0x00,0x00,0x08,0x20,0x00,0xF8,0x19,0x00,0x00,0x04,0x00,0x00,0x03,0x00,0x80,0x38,0x00,0x60,0x24,0x00,0x00,0x7E,0x00,0x00,0x20,0x00,0x00,0x20,	// 188
	0x00,0x00,0x00,0x10,0x00,0x00,0x08,0x20,0x00,0xF8,0x19,0x00,0x00,0x04,0x00,0x00,0x03,0x00,0x80,0x04,0x00,0x60,0x62,0x00,0x00,0x62,0x00,0x00,0x52,0x00,0x00,0x4C,	// 189
	0x00,0x00,0x00,0x98,0x00,0x00,0x28,0x01,0x00,0x28,0x21,0x00,0xD8,0x19,0x00,0x00,0x04,0x00,0x00,0x03,0x00,0x80,0x38,0x00,0x60,0x24,0x00,0x00,0x7E,0x00,0x00,0x20,0x00,0x00,0x20,	// 190
	0x00,0x00,0x00,0x00,0xF0,0x01,0x00,0x08,0x02,0x40,0x06,0x02,0x00,0x00,0x02,0x00,0x80,0x01,	// 191
	0x00,0x40,0x00,0x00,0x30,0x00,0x00,0x0F,0x00,0xE1,0x08,0x00,0x1A,0x08,0x00,0x70,0x08,0x00,0x80,0x09,0x00,0x00,0x0E,0x00,0x00,0x70,0x00,0x00,0x40,	// 192
	0x00,0x40,0x00,0x00,0x30,0x00,0x00,0x0F,0x00,0xE0,0x08,0x00,0x1A,0x08,0x00,0x71,0x08,0x00,0x80,0x09,0x00,0x00,0x0E,0x00,0x00,0x70,0x00,0x00,0x40,	// 193
	0x00,0x40,0x00,0x00,0x30,0x00,0x00,0x0F,0x00,0xE2,0x08,0x00,0x19,0x08,0x00,0x71,0x08,0x00,0x82,0x09,0x00,0x00,0x0E,0x00,0x00,0x70,0x00,0x00,0x40,	// 194
	0x00,0x40,0x00,0x00,0x30,0x00,0x02,0x0F,0x00,0xE1,0x08,0x00,0x19,0x08,0x00,0x72,0x08,0x00,0x83,0x09,0x00,0x00,0x0E,0x00,0x00,0x70,0x00,0x00,0x40,	// 195
	0x00,0x40,0x00,0x00,0x30,0x00,0x01,0x0F,0x00,0xE0,0x08,0x00,0x18,0x08,0x00,0x70,0x08,0x00,0x81,0x09,0x00,0x00,0x0E,0x00,0x00,0x70,0x00,0x00,0x40,	// 196
	0x00,0x40,0x00,0x00,0x30,0x00,0x00,0x0F,0x00,0xE0,0x08,0x00,0x1B,0x08,0x00,0x72,0x08,0x00,0x81,0x09,0x00,0x00,0x0E,0x00,0x00,0x70,0x00,0x00,0x40,	// 197
	0x00,0x40,0x00,0x00,0x30,0x00,0x00,0x0C,0x00,0x00,0x0A,0x00,0x80,0x09,0x00,0x60,0x08,0x00,0x10,0x08,0x00,0xF8,0x3D,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x00,0x40,	// 198
	0x00,0x00,0x00,0xE0,0x1F,0x00,0x10,0x20,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0xC0,0x02,0x08,0x40,0x03,0x10,0x20,0x00,0x60,0x18,	// 199
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0x09,0x42,0x00,0x0A,0x42,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x42,	// 200
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x0A,0x42,0x00,0x09,0x42,0x00,0x08,0x42,	// 201
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0x0A,0x42,0x00,0x09,0x42,0x00,0x09,0x42,0x00,0x0A,0x42,0x00,0x08,0x42,	// 202
	0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0x7F,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x09,0x42,0x00,0x08,0x42,	// 203
	0x01,0x00,0x00,0xFA,0x7F,	// 204
	0x00,0x00,0x00,0x00,0x00,0x00,0xFA,0x7F,0x00,0x01,	// 205
	0x02,0x00,0x00,0xF9,0x7F,0x00,0x01,0x00,0x00,0x02,	// 206
	0x01,0x00,0x00,0xF8,0x7F,	// 207
	0x00,0x00,0x00,0xF0,0x3F,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x42,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x10,0x20,0x00,0x20,0x10,0x00,0xC0,0x0F,	// 208
	0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x62,0x00,0x00,0x81,0x00,0x00,0x01,0x03,0x00,0x02,0x04,0x00,0x03,0x18,0x00,0x00,0x20,0x00,0xF8,0x7F,	// 209
	0x00,0x00,0x00,0xE0,0x1F,0x00,0x10,0x20,0x00,0x09,0x40,0x00,0x0A,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x30,0x30,0x00,0xC0,0x0F,	// 210
	0x00,0x00,0x00,0xE0,0x1F,0x00,0x10,0x20,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x0A,0x40,0x00,0x09,0x40,0x00,0x08,0x40,0x00,0x30,0x30,0x00,0xC0,0x0F,	// 211
	0x00,0x00,0x00,0xE0,0x1F,0x00,0x10,0x20,0x00,0x0A,0x40,0x00,0x09,0x40,0x00,0x09,0x40,0x00,0x0A,0x40,0x00,0x08,0x40,0x00,0x30,0x30,0x00,0xC0,0x0F,	// 212
	0x00,0x00,0x00,0xE0,0x1F,0x00,0x12,0x20,0x00,0x09,0x40,0x00,0x09,0x40,0x00,0x0A,0x40,0x00,0x0B,0x40,0x00,0x08,0x40,0x00,0x30,0x30,0x00,0xC0,0x0F,	// 213
	0x00,0x00,0x00,0xE0,0x1F,0x00,0x10,0x20,0x00,0x09,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x09,0x40,0x00,0x30,0x30,0x00,0xC0,0x0F,	// 214
	0x00,0x00,0x00,0x00,0x61,0x00,0x00,0x16,0x00,0x00,0x08,0x00,0x00,0x14,0x00,0x00,0x22,0x00,0x00,0x41,	// 215
	0x00,0x00,0x00,0xE0,0x1F,0x00,0x10,0x60,0x00,0x18,0x50,0x00,0x08,0x4C,0x00,0x08,0x43,0x00,0x88,0x40,0x00,0x68,0x40,0x00,0x38,0x30,0x00,0xC8,0x0F,	// 216
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x3F,0x00,0x00,0x40,0x00,0x01,0x40,0x00,0x02,0x40,0x00,0x00,0x40,0x00,0x00,0x60,0x00,0xF8,0x3F,	// 217
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x3F,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x02,0x40,0x00,0x01,0x40,0x00,0x00,0x60,0x00,0xF8,0x3F,	// 218
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x3F,0x00,0x02,0x40,0x00,0x01,0x40,0x00,0x01,0x40,0x00,0x02,0x40,0x00,0x00,0x60,0x00,0xF8,0x3F,	// 219
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x3F,0x00,0x01,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x01,0x60,0x00,0xF8,0x3F,	// 220
	0x08,0x00,0x00,0x30,0x00,0x00,0x40,0x00,0x00,0x80,0x01,0x00,0x02,0x7E,0x00,0x01,0x03,0x00,0xC0,0x00,0x00,0x20,0x00,0x00,0x18,	// 221
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0x40,0x10,0x00,0x40,0x10,0x00,0x40,0x10,0x00,0x40,0x10,0x00,0x80,0x08,0x00,0x00,0x07,	// 222
	0x00,0x00,0x00,0xF0,0x7F,0x00,0x08,0x20,0x00,0x08,0x40,0x00,0x88,0x41,0x00,0x70,0x42,0x00,0x00,0x44,0x00,0x00,0x38,	// 223
	0x00,0x00,0x00,0x80,0x3C,0x00,0x40,0x42,0x00,0x48,0x42,0x00,0x50,0x42,0x00,0x40,0x22,0x00,0x80,0x7F,	// 224
	0x00,0x00,0x00,0x80,0x3C,0x00,0x40,0x42,0x00,0x40,0x42,0x00,0x50,0x42,0x00,0x48,0x22,0x00,0x80,0x7F,	// 225
	0x00,0x00,0x00,0x80,0x3C,0x00,0x50,0x42,0x00,0x48,0x42,0x00,0x48,0x42,0x00,0x50,0x22,0x00,0x80,0x7F,	// 226
	0x00,0x00,0x00,0x90,0x3C,0x00,0x48,0x42,0x00,0x48,0x42,0x00,0x50,0x42,0x00,0x58,0x22,0x00,0x80,0x7F,	// 227
	0x00,0x00,0x00,0x80,0x3C,0x00,0x48,0x42,0x00,0x40,0x42,0x00,0x40,0x42,0x00,0x40,0x22,0x00,0x88,0x7F,	// 228
	0x00,0x00,0x00,0x80,0x3C,0x00,0x40,0x42,0x00,0x5C,0x42,0x00,0x54,0x42,0x00,0x48,0x22,0x00,0x80,0x7F,	// 229
	0x00,0x00,0x00,0x80,0x39,0x00,0x40,0x44,0x00,0x40,0x44,0x00,0x40,0x44,0x00,0x40,0x44,0x00,0x80,0x3F,0x00,0x80,0x24,0x00,0x40,0x44,0x00,0x40,0x44,0x00,0x40,0x44,0x00,0x40,0x44,0x00,0x80,0x47,	// 230
	0x00,0x00,0x00,0x80,0x3F,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0xC0,0x02,0x40,0x40,0x03,0x80,0x31,	// 231
	0x00,0x00,0x00,0x80,0x3F,0x00,0xC0,0x44,0x00,0x48,0x44,0x00,0x50,0x44,0x00,0x40,0x44,0x00,0x80,0x27,	// 232
	0x00,0x00,0x00,0x80,0x3F,0x00,0xC0,0x44,0x00,0x40,0x44,0x00,0x50,0x44,0x00,0x48,0x44,0x00,0x80,0x27,	// 233
	0x00,0x00,0x00,0x80,0x3F,0x00,0xD0,0x44,0x00,0x48,0x44,0x00,0x48,0x44,0x00,0x50,0x44,0x00,0x80,0x27,	// 234
	0x00,0x00,0x00,0x80,0x3F,0x00,0xC8,0x44,0x00,0x40,0x44,0x00,0x40,0x44,0x00,0x40,0x44,0x00,0x88,0x27,	// 235
	0x08,0x00,0x00,0xD0,0x7F,	// 236
	0x00,0x00,0x00,0xD0,0x7F,0x00,0x08,	// 237
	0x10,0x00,0x00,0xC8,0x7F,0x00,0x08,	// 238
	0x00,0x00,0x00,0xC0,0x7F,	// 239
	0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0x22,0x00,0x48,0x41,0x00,0x50,0x41,0x00,0x30,0x41,0x00,0x70,0x21,0x00,0x90,0x1F,	// 240
	0x00,0x00,0x00,0xD0,0x7F,0x00,0x88,0x00,0x00,0x48,0x00,0x00,0x50,0x00,0x00,0x58,0x00,0x00,0xC0,0x00,0x00,0x00,0x7F,	// 241
	0x00,0x00,0x00,0x00,0x1F,0x00,0x80,0x20,0x00,0x48,0x40,0x00,0x50,0x40,0x00,0x40,0x40,0x00,0x80,0x20,0x00,0x00,0x1F,	// 242
	0x00,0x00,0x00,0x00,0x1F,0x00,0x80,0x20,0x00,0x40,0x40,0x00,0x50,0x40,0x00,0x48,0x40,0x00,0x80,0x20,0x00,0x00,0x1F,	// 243
	0x00,0x00,0x00,0x00,0x1F,0x00,0x90,0x20,0x00,0x48,0x40,0x00,0x48,0x40,0x00,0x50,0x40,0x00,0x80,0x20,0x00,0x00,0x1F,	// 244
	0x00,0x00,0x00,0x10,0x1F,0x00,0x88,0x20,0x00,0x48,0x40,0x00,0x50,0x40,0x00,0x58,0x40,0x00,0x80,0x20,0x00,0x00,0x1F,	// 245
	0x00,0x00,0x00,0x00,0x1F,0x00,0x88,0x20,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x88,0x20,0x00,0x00,0x1F,	// 246
	0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x02,0x00,0x00,0x02,0x00,0x40,0x22,0x00,0x00,0x02,0x00,0x00,0x02,0x00,0x00,0x02,	// 247
	0x00,0x00,0x00,0x00,0xBF,0x00,0x80,0x60,0x00,0x40,0x58,0x00,0x40,0x46,0x00,0xC0,0x41,0x00,0xE0,0x20,0x00,0x00,0x1F,	// 248
	0x00,0x00,0x00,0xC0,0x1F,0x00,0x00,0x60,0x00,0x08,0x40,0x00,0x10,0x40,0x00,0x00,0x40,0x00,0x00,0x20,0x00,0xC0,0x7F,	// 249
	0x00,0x00,0x00,0xC0,0x1F,0x00,0x00,0x60,0x00,0x00,0x40,0x00,0x10,0x40,0x00,0x08,0x40,0x00,0x00,0x20,0x00,0xC0,0x7F,	// 250
	0x00,0x00,0x00,0xC0,0x1F,0x00,0x10,0x60,0x00,0x08,0x40,0x00,0x08,0x40,0x00,0x10,0x40,0x00,0x00,0x20,0x00,0xC0,0x7F,	// 251
	0x00,0x00,0x00,0xC0,0x1F,0x00,0x08,0x60,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x08,0x20,0x00,0xC0,0x7F,	// 252
	0x00,0x00,0x00,0xC0,0x03,0x02,0x00,0x0C,0x02,0x00,0xF0,0x01,0x10,0x38,0x00,0x08,0x06,0x00,0xC0,0x01,0x00,0x40,	// 253
	0x00,0x00,0x00,0xF8,0xFF,0x03,0x80,0x20,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x40,0x40,0x00,0x80,0x20,0x00,0x00,0x1F,	// 254
	0x00,0x00,0x00,0xC0,0x03,0x02,0x08,0x0C,0x02,0x00,0xF0,0x01,0x00,0x38,0x00,0x00,0x06,0x00,0xC8,0x01,0x00,0x40	// 255
};