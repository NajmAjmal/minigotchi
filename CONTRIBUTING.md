# Minigotchi contributing guidelines
Hello everyone, whether you be from hacktoberfest or just some random person who stumbled upon this repository. Be sure to follow our contributing guidelines! This project needs just as much help from the community as it does from the maintainer itself.
#
## How can I contribute?
1. Fork and clone the repository

`git clone https://github.com/<your username>/minigotchi.git`

2. Go into cloned folder

`cd minigotchi`

3. Create a branch

`git checkout -b feature/your-feature`

3. Make your changes!

4. Test

I recommend getting the hardware needed and making sure this works. Test using the Arduino IDE(Not the web editor), and make sure the appropriate board is selected. I am using the latest version, and so should you. 

5. Commit and push

`git commit -m "Add your concise commit message"`

`git push origin feature/your-feature`

6. Open a pull request

Go to your forked repository on GitHub, switch to the branch you just pushed, and click on the "New Pull Request" button. Fill out the necessary information and submit the pull request.
##
# Code structure
Most of the code is object oriented. I essentially grouped all of the main functions into their own .cpp and .h files, then inclded those files in the main .ino file. Here's some more info on the [OOP(Object oriented programming)](https://en.wikipedia.org/wiki/Object-oriented_programming).
#
