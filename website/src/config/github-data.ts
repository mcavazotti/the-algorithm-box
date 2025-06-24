interface GithubData {
  host: string;
  organization: string;
  repository: string;
  deploymentBranch: string;
  repositoryAddress: () => string;
}

export default {
  host: "https://github.com",
  organization: "mcavazotti",
  repository: "the-algorithm-box",
  deploymentBranch: "master",
  repositoryAddress() {
    return [this.host, this.organization, this.repository].join("/");
  },
} satisfies GithubData;
