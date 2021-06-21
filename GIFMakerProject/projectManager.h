#ifndef PROJECTMANAGERH
#define PROJECTMANAGERH

/// <summary>
/// Asks user path to save current project
/// </summary>
/// <param name="head">Current project data (list of frames) (frame node)</param>
void saveProject(FrameNode* head);
/// <summary>
/// asks the user if he want to load project from some path
/// </summary>
/// <returns>Data that was loaded (if not loaded - returns NULL)</returns>
FrameNode* askLoadProject();
/// <summary>
/// If the user chose to load the project this function will load the project from the given path
/// </summary>
/// <param name="projectPath">Path which contains the project to load</param>
/// <returns>Data that was loaded</returns>
FrameNode* loadProject(char* projectPath);

#endif