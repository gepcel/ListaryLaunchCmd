# ListaryLaunchCmd

A small tool to launch the Command Prompt (Windows) in a specific folder. Useful for creating an action in [Listary](https://www.listary.com/).

With Listary, you can create an action to launch the Command Prompt in a search result folder. Listary provides two types of arguments: `{action_path}` and `{action_path:parent}`. `{action_path}` should be used when calling the action on a folder, while `{action_path:parent}` should be used when calling it on a file. Ideally, there should be some intelligence to automatically determine which one to use, for example, `{action_path}` if it points to a directory, otherwise `{action_path:parent}`.


There was already a [discussion](https://discussion.listary.com/t/path-with-action-variant-of-action-path-and-action-path-parent/3854) about this in 2017, where the author agreed to add such a parameter, but it still hasn't been implemented. Hence, this small tool.

The tool is written in both C# and C++. Check the few lines of code and choose whichever you prefer.