import { defineConfig } from "astro/config";
import starlight from "@astrojs/starlight";
import mdx from "@astrojs/mdx";
import react from "@astrojs/react";
import githubData from "./src/config/github-data";

// https://astro.build/config
export default defineConfig({
  integrations: [
    react(),
    starlight({
      title: "The Algorithm Box",
      logo: {
        src: "./src/assets/Logo.png",
      },
      customCss: ["./src/styles/custom.css"],

      social: [{ icon: "github", label: "GitHub", href: githubData.repositoryAddress() }],
      favicon: "favicon.ico",
	  credits: true,
      sidebar: [
        {
          label: "Code",
          autogenerate: { directory: "code" },
        },
      ],
    }),
    mdx(),
  ],
});
