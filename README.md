# isotopic-periodic-table-series
## Self-made Academic Periodic Table Collection (Isotopic Version as core work)
自制学术全套元素周期表系列（同位素版本为本项目核心工作量）
> Project Goal: Iterative, finely annotated periodic table charts for chemistry & nuclide enthusiasts.
> 项目目的：持续迭代、精细标注的多套周期表图集，面向化学、核素爱好者。

## 🎇 Release: 2026-09-26
### ✨ 发布版本：2026-09-26
Initial upload to GitHub, full set of academic periodic charts.
首次上传至GitHub，全套学术周期表图集。

Features:
- 5 distinct academic periodic table charts in total
包含5张不同体系的学术元素周期表
- All charts added with author signature
全部图表添加作者铭牌
- The core isotopic periodic table annotated with short-lived transient nuclides dynamically produced inside stars
核心同位素周期表标注恒星内动态生成的短命瞬态核素
- Legend for quasi-stable nuclides (quasi-stable)
设置准稳定核素图例（quasi-stable）


## 🧾 Included Materials
### 🧾 包含资料清单
#### 5 Main Academic Periodic Tables（5张主学术周期表）
- Chinese-English pronunciation periodic table
  中英文读音版元素周期表
- Electron configuration periodic table
  电子排布版元素周期表
- Pauling scale electronegativity periodic table
  鲍林标度电负性版元素周期表
- Extended periodic table by Pekka Pyykkö model
  佩卡·皮寇（Pekka Pyykkö）模型扩展元素周期表
- Isotopic Periodic Table (Core: quasi-stable nuclides, stellar transient nuclides)
  同位素元素周期表（核心：准稳定核素、恒星瞬态核素标记）

#### 2 Supplementary Sheets（2页配套附表）
- Representative list of radioactive isotopes (Page 1)
  放射性同位素代表列表（第一页）
- Representative list of radioactive isotopes (Page 2)
  放射性同位素代表列表（第二页）

### 📁 Data Files 数据文件
- `/data/nuclide-count-stat.xlsx`: Nuclide statistics sheet, recording mass number range and isotope count of each element.
- `/data/nuclide-count-stat.xlsx`：核素统计表，记录各元素同位素质量数范围与同位素种类统计
- `/data/IPAs.txt`: List of element English names & IPA transcriptions.
- `/data/IPAs.txt`：元素英文名称国际音标列表
- `/electro_negativity_colors.cpp`: C++ source, interpolate and generate cell hex-color from Pauling electronegativity.
- `/electro_negativity_colors.cpp`：C++源码，根据鲍林电负性插值生成周期表单元格十六进制底色。
- `source/Blank_Periodic_Table_Base.xlsx`: Blank base template of periodic table grid in Excel format.
- `source/Blank_Periodic_Table_Base.xlsx`：Excel格式空白周期表网格基底模板。

#### Source File
- Adobe Illustrator source files: Separate `.ai` project for each chart, text remains editable
  Adobe Illustrator 源文件：每张图表独立的`.ai`工程文件，文字保留可编辑状态

### Font Notice 字体说明
Fonts used: STIX Two & LXGW WenKai (霞鹜文楷). Both licensed under SIL OFL 1.1.
本图集使用字体：STIX Two、霞鹜文楷，两款字体均采用 SIL OFL 1.1 开源协议。
To edit text inside the `.ai` file, please install these two fonts on your device first.
如需编辑ai源文件内文字，请预先安装上述两款字体。
Download 下载链接：
- STIX Two: https://github.com/stipub/stixfonts
- LXGW WenKai (霞鹜文楷): https://github.com/lxgw/LxgwWenKai

## 📖 Instructions
### 使用说明
Open the original high-resolution image to read the tiny nuclide annotations.
点击图片打开原始高清版本，才能看清同位素小字标注。
Source .ai file is provided for further annotation and modification under CC BY-SA 4.0.
提供.ai源文件，可在CC BY-SA 4.0协议下继续标注、修改图表。
For chemistry olympiad, inorganic chemistry and nuclear physics enthusiasts.
适合化竞、无机化学、核物理爱好者参考学习。

## 📜 License 许可协议
This work is licensed under CC BY-SA 4.0 International.
本作品采用知识共享署名-相同方式共享 4.0 国际许可协议进行许可。
See the [LICENSE](./LICENSE) file for full license text.
完整协议文本请参阅 [LICENSE](./LICENSE) 文件。

## Preview 预览图
![同位素元素周期表预览](images/main-tables/05-isotopic-periodic-table.png)

### 📖 Project Journal 项目纪实

- On May 24, 2026, I stayed up late after drinking too much tea and fell asleep at 4:30 a.m., waking naturally around 9 a.m. While groggy, I wanted to correct my pronunciation of English element names and looked for a periodic table with IPA transcriptions. No complete digital version could be found online. The only option was a $28.99 printed poster by Leskoff, whose preview images made the IPA text illegible. Drawing on design‑class experience with Photoshop and Adobe Illustrator, I decided to draw one myself.
- 2026年5月24日，前一晚饮茶过多熬夜，凌晨四点半才入睡，九点多自然醒来。昏沉之间，我想校准元素英文名读音，希望找到一张带国际音标的元素周期表。网上找不到可用的完整数字版本，仅有Leskoff售价28.99美元的实体海报，预览图中音标完全看不清。凭借初中设计课学习Photoshop与Adobe Illustrator的基础，我决定亲手绘制一张。

- I created an A4 landscape canvas in Illustrator, built near‑square grid cells from an Excel sheet, captured screenshots of the grid base, removed backgrounds in Photoshop, then assembled and populated every cell inside Illustrator. Layout included atomic number, relative atomic mass, element symbol, Chinese name, Pinyin, American English name and American IPA. After copying styles across cells and fine‑tuning text positions, I exported at 1000 ppi for high fidelity.
- 在Illustrator中新建A4横向画布；由Excel制作近似正方形网格；截图得到网格基底，在Photoshop去除白底，再导入Ai排版。逐个格子填入原子序数、相对原子质量、元素符号、中文名、拼音、美式英文名与美式音标。批量复制文本样式、微调文字位置，最终以1000ppi分辨率导出高清成品。

- I adopted dual‑scheme coloring: ten‑category color fill for cell backgrounds following international conventions, plus solid‑red lines marking the metal‑nonmetal dividing line. The soft pastel hex colors give an effect I describe as cream from ten different fruit cakes, retaining rainbow‑like visual impact without obscuring text content.
- 配色采用双轨方案：格子底色使用国际通用十分区配色，金属‑非金属分界线使用纯红色框线。分区浅十六进制色号柔和，效果如同十种不同水果蛋糕的奶油，拥有彩虹观感同时不会盖住文字。

- On May 25, 2026, I intended to publish my newly‑finished first self‑made periodic table on Baidu Chemistry Bar. I searched for existing similar works and found no precedents. I replied to a post asking for ways to memorize chemical elements and shared my practical learning experience. My post was removed and my account banned by moderators for "necroposting". This was not my first time encountering such treatment.
- 2026年5月25日，我打算把刚完成的第一张自制周期表发布到化学吧。检索后没有找到同类先例。看到有人求助记忆化学元素的方法，我分享了自己实操的学习经验，帖子随即被吧务以挖坟理由删除，账号遭到封禁。这并非我第一次遇到这类处理。

- This incident unexpectedly became a turning point. I lost faith in Baidu Tieba as a platform. In practice, it acts as a free Q&A space while also being an emotional outlet for moderators. I permanently uninstalled the Baidu Tieba app and swore I would never voluntarily access Baidu Tieba again, unless in the event of compensation.
- 这件事意外成为转折点。我彻底对百度贴吧失去信心。它实质上是免费答疑区，同时也是吧务的情绪宣泄场。我永久卸载百度贴吧APP，发誓不会主动进入百度贴吧，除非获得相应赔偿。

- Chemistry questions can now be solved with AI assistants such as Doubao and DeepSeek, though they occasionally produce out‑of‑bound answers. This experience pushed me toward self‑hosted open‑source publication.
- 化学答疑现在可以依靠豆包、DeepSeek等AI助手完成，尽管偶尔模型会输出越界内容。这次经历推动我走向自主托管的开源发布。

- On May 28, 2026, I produced the electron‑configuration periodic table. It lists full condensed electron configurations with valence‑shell parts marked red, alongside per‑shell electron counts formatted to fit Oganesson. Spdf block markers are placed on atomic‑number digits: helium belongs to s‑block; lutetium and lawrencium belong to d‑block.
- 2026年5月28日，完成电子排布版周期表。表中列出完整简化电子排布式，价层部分标红，附带各能层电子数，排版以鿫为边界基准。在原子序数上标记spdf分区：氦归入s区，镥、铹归入d区。

- On June 8, 2026, after clearing speed trials in *A Dance of Fire and Ice‑New Cosmos*, I built a Pauling‑scale electronegativity periodic table. With assistance from Doubao, I wrote C++ code to interpolate gradient background colors. Some electronegativity values for noble gases and super‑heavy elements are theoretical predictions. The resulting color distribution resembles the asymmetry between matter and antimatter in the universe; the whole chart feels like a disco dance floor supervised by periodic‑law and relativistic effects.
- 2026年6月8日，通关《冰与火之舞》新宇宙全部普通关飙速试炼后，制作鲍林标度电负性周期表。在豆包协助下编写C++代码插值生成渐变底色。部分稀有气体与超重元素电负性为理论计算值。生成的色彩分布如同宇宙中正物质与反物质的不对称，整张表仿佛是由元素周期律与相对论效应监制的迪斯科舞池。

- On June 9, 2026, I completed the extended periodic table following Pekka Pyykkö’s model for eighth‑ and ninth‑period elements. Spin‑orbit splitting disturbs the Madelung rule; 8p₁/₂ and 9p₁/₂ orbitals shift to unexpected energy positions. The table spans 14 columns and cannot fit its legend on an A4 canvas.
- 2026年6月9日，依据佩卡·皮寇模型完成8、9周期扩展元素周期表。自旋‑轨道耦合分裂打乱构造原理，8p₁/₂、9p₁/₂轨道能级发生偏移。整张表共14列，图例无法在A4画布内放下。

- On June 10‑11, 2026, motivated by shortcomings in standard textbook tables, I created the isotope‑focused periodic table. Textbook treatments often fail to distinguish half‑lives of radioactive isotopes and omit well‑known radionuclides. I used range notation for artificial isotopes, reordered isotope enumeration, and introduced a dedicated color for quasi‑stable nuclides. Two days of work yielded this “family portrait of nuclides”.
- 2026年6月10‑11日，受教材周期表的诸多不足启发，着手制作同位素版周期表：教材不区分放射性同位素半衰期，部分知名放射性核素直接缺失。我使用区间表示人造同位素，改变同位素排布顺序，为准稳定核素单独设立颜色。连续两日完成这张“核素全家福”。

- On August 16, 2026, inspired by Glenn T. Seaborg’s composite periodic‑table appendix, I compiled supplementary tables of representative radioactive isotopes. Each element’s entries stay within one column to avoid page‑flipping when reading. Remaining space is used for decay‑mode legends and example decay equations accessible even for beginners.
- 2026年8月16日，受西博格综合周期表附表启发，制作代表性放射性同位素附表。每个元素内容限制在同一列，避免阅读时反复翻页。剩余版面放置衰变方式图例与衰变方程式示例，降低入门阅读门槛。

- On August 25, 2026, I standardized all non‑Chinese typefaces to the open‑source, commercially‑permitted STIX Two font. I added creation‑date and last‑modified‑date marks in the bottom‑left corner for version tracking.
- 2026年8月25日，将全部非中文文本统一更换为开源可商用STIX Two字体；左下角标注初创日期与修改日期，用于版本追溯。

- On September 5, 2026, Chinese fonts were migrated from closed‑source Feihua Song to the open‑source, freely‑licensed LXGW WenKai. This brings more humanistic readability and avoids risks from discontinued font maintenance for future new‑created Chinese characters of super‑heavy elements.
- 2026年9月5日，中文字体由闭源飞花宋体迁移至开源免费商用霞鹜文楷。阅读更富人文气息，同时规避未来超重元素新造字的字体维护风险。

- On September 12, 2026, I launched the **Element Dossier** series. Each element receives its own dossier recording basic data, physical‑chemical properties and representative chemical equations, for deeper exploration of elemental chemistry.
- 2026年9月12日，启动**元素户口簿 Element Dossier**系列。为每一种元素建立档案，记录基础信息、理化性质与代表性化学方程式，深入研究各元素化学行为。

- On September 26, 2026, I published the complete collection of academic periodic tables on GitHub under the CC BY‑SA 4.0 International Public License. The goal is to permanently preserve these works so they can continue to serve chemistry enthusiasts, independent of any single web community.
- 2026年9月26日，全套学术周期表在GitHub以 CC BY‑SA 4.0 国际协议开源发布。目的是永久留存这份作品，使其可以持续服务化学爱好者，不再依附任何单一网络社群。
