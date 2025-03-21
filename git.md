### 初始化git仓库git init

```git
git init
```
该命令将创建一个名为 .git 的子目录，这个子目录含有你初始化的 Git 仓库中所有的必须文件，这些文件是 Git 仓库的骨干。 但是，在这个时候，我们仅仅是做了一个初始化的操作，你的项目里的文件还没有被跟踪。

### 追踪文件git add
可以用它开始跟踪新文件，或者把已跟踪的文件(进行过修改的)放到暂存区，还能用于合并时把有冲突的文件标记为已解决状态等
```
$ git add 文件名.后缀
```
文件将被跟踪并处于暂存状态  
### 克隆仓库git clone <url>

```
$ git clone <url>
$ git clone https://github.com/libgit2/libgit2
如果你想在克隆远程仓库的时候，自定义本地仓库的名字，你可以通过额外的参数指定新的目录名：$ git clone https://github.com/libgit2/libgit2 mylibgit
```

```
如果你想在克隆远程仓库的时候，自定义本地仓库的名字，你可以通过额外的参数指定新的目录名：
$ git clone https://github.com/libgit2/libgit2 mylibgit
```

### 检查当前文件状态git status
```
git status
```
### 查看尚未暂存的文件更新了哪些部分git diff：
请注意，git diff 本身只显示尚未暂存的改动，而不是自上次提交以来所做的所有改动。
```
git diff
```

### 提交git commit -m
在 commit 命令后添加 -m 选项，将提交注释信息与命令放在同一行
```
$ git commit -m "这里是注释内容,通常写改动信息"
$ git commit -m "Story 182: Fix benchmarks for speed"
```

跳过使用暂存区域,自动把所有已经跟踪过的文件暂存起来一并提交，从而跳过 git add 步骤

```
git commit -a -m '注释信息'
```

### 移除文件
Git 本地数据管理，大概可以分为三个区：

工作区（Working Directory）：是可以直接编辑的地方。
暂存区（Stage/Index）：数据暂时存放的区域。
版本库（commit History）：存放已经提交的数据。

#### rm命令
作用: 删除工作区的文件,但不删除版本库的文件
```
$ rm test.txt
```
结果：成功删除工作区文件
想要删除版本库文件还要执行下面的命令
```
$ git add test.txt
$ git commit -m "delete test"
```
结果： 删除了工作区和版本库的文件。  

#### git rm 命令  
作用： 删除工作区文件，并且将这次删除放入暂存区。
注意： 要删除的文件是没有修改过的，就是说和当前版本库文件的内容相同。
```
$ git rm test.txt
```
查看状态（成功删除了工作区文件，并且将这次删除放入暂存区。）
```
$ git commit -m "delete test"
```
结果:删除了工作区和版本库的文件，因为暂存区不可能有该文件（如果有意味着该文件修改后 git add 到暂存区，那样 git rm 命令会报错，如下面的情况）

#### git rm -f 命令  
作用： 删除工作区和暂存区文件，并且将这次删除放入暂存区。
注意： 要删除的文件已经修改过，就是说和当前版本库文件的内容不同。
当文件修改后不管有没有 git add 到暂存区，使用 git rm 命令删除都会报错。这时我们要使用git rm -f删除
```
$ git rm -f test.txt
```
查看状态（成功删除工作区和暂存区文件，并且将这次删除放入暂存区。）然后提交
```
$ git commit -m "delete test"
```
结果： 删除了工作区、暂存区和版本库的文件。

#### git rm --cached 命令
作用： 删除暂存区文件，但保留工作区的文件，并且将这次删除放入暂存区。从此不再跟踪该文件(你想让文件保留在磁盘，但是并不想让 Git 继续跟踪。)
```
$ git rm --cached test.txt
```
查看状态（成功删除暂存区文件，保留工作区文件，并且将这次删除放入暂存区，注意这里文件取消了跟踪）
然后提交：
```
$ git commit -m "delete test"成功删除了版本库文件
```
 结果： 删除了暂存区和版本库的文件，但保留了工作区的文件(从此以后不再跟踪)。如果文件有修改并 git add 到暂存区，再执行 git rm --cached 和 git commit，那么保留的工作区文件是修改后的文件，同时暂存区的修改文件和版本库的文件也被删了。

 ### 重命名文件git mv A B
 将文件从A命名为B
 ```
 $ git mv A B
 ```
 其实，运行 git mv 就相当于运行了下面三条命令：
 ```
$ mv README.md README
$ git rm README.md
$ git add README
 ```
### 查看提交历史git log
不传入任何参数的默认情况下，git log 会按时间先后顺序列出所有的提交，最近的更新排在最上面  
这个命令会列出每个提交的 SHA-1 校验和、作者的名字和电子邮件地址、提交时间以及提交说明。

```
git log
```
#### git log -p 
它会显示每次提交所引入的差异（按 补丁 的格式输出）
```
git log -p
```
#### git log -2 
你也可以限制显示的日志条目数量，例如使用 -2 选项来只显示最近的两次提交
```
git log -2
```
#### git log --stat
每次提交的简略统计信息
```
git log --stat
```
#### git log --since=
出最近两周的所有提交
```
$ git log --since=2.weeks
```
#### git log  --author
显示指定作者的提交

####  实际的例子
来看一个实际的例子，如果要在 Git 源码库中查看 Junio Hamano 在 2008 年 10 月其间， 除了合并提交之外的哪一个提交修改了测试文件，可以使用下面的命令：
```
$ git log --pretty="%h - %s" --author='Junio C Hamano' --since="2008-10-01" \
   --before="2008-11-01" --no-merges -- t/
```

### 撤消操作$ git commit --amend
有时候我们提交完了才发现漏掉了几个文件没有添加，或者提交信息写错了。 此时，可以运行带有 --amend 选项的提交命令来重新提交：
```
$ git commit --amend
```
这个命令会将暂存区中的文件提交。 如果自上次提交以来你还未做任何修改（例如，在上次提交后马上执行了此命令）， 那么快照会保持不变，而你所修改的只是提交信息。
最终你只会有一个提交——第二次提交将代替第一次提交的结果。


### 推送到远程仓库
```Git
git add README.md
git commit -m "更新 README：添加项目说明和目录结构"
git push origin main
```

### 创建操作

#### 创建md 文件

```git
touch 文件名.md
```

### 删除操作
#### 暂存删除操作
```Git
git add -u "文件名.后缀"
```

#### 恢复删除的文件
```git
git restore "文件名.后缀"
```
#### 删除文件夹
```git
$ rm -rf 线性表
```
