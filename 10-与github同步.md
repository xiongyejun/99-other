# 1. 配置当前当前fork的仓库的原仓库地址 #
	git remote add upstream <原仓库github地址>
# 2. 查看当前仓库的远程仓库地址和原仓库地址 #
	git remote -v
# 3. 获取原仓库的更新。使用fetch更新，fetch后会被存储在一个本地分支upstream/master上。 #
	git fetch upstream
# 4. 合并到本地分支。切换到本地master分支，合并upstream/master分支。 #
	git merge upstream/master